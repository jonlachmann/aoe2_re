/* Boot the lifted AoE2 through the win32hle host (permissive bring-up),
 * with a fault tracer mapping the faulting host address to the guest VA. */
#define _XOPEN_SOURCE 700
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <mach-o/ldsyms.h>
#include <signal.h>
#include <mach-o/ldsyms.h>
#include <ucontext.h>
#include <execinfo.h>
#include "win32hle.h"
#include "host.h"
#include "recomp_trace.h"
#include <SDL2/SDL.h>

extern const win32hle_shim win32hle_aoe[];
extern ptrdiff_t g_mem_base;

static void fault_handler(int sig, siginfo_t* si, void* uctx) {
    uintptr_t host_addr = (uintptr_t)si->si_addr;
    ptrdiff_t guest = (ptrdiff_t)host_addr - g_mem_base;
    extern uint32_t g_cur_func;
    recomp_trace_flush();
    recomp_dump_trace("guest fault");
    {
        extern uint32_t g_eax, g_ecx, g_edx, g_ebx, g_esp, g_ebp, g_esi, g_edi;
        ucontext_t *uc = (ucontext_t *)uctx;
        void *rip = (void *)(uintptr_t)uc->uc_mcontext->__ss.__pc;
        {   /* host backtrace with symbols */
            void *bt[64];
            int n = backtrace(bt, 64);
            char **sy = backtrace_symbols(bt, n);
            fprintf(stderr, "  HOST BACKTRACE (%d frames):\n", n);
            for (int k = 0; k < n && k < 24; k++) fprintf(stderr, "    [%d] %s\n", k, sy[k]);
            free(sy);
        }
        {   /* esp ring tail: where did the guest stack go? */
            extern uint32_t g_esp_ring[4096];
            extern unsigned g_esp_idx;
            fprintf(stderr, "  [esp ring] n=%u\n", g_esp_idx);
            unsigned n = g_esp_idx < 40 ? g_esp_idx : 40;
            for (unsigned k = 0; k < n; k++) {
                uint32_t e = g_esp_ring[(g_esp_idx - n + k) & 4095u];
                fprintf(stderr, "    esp[%u]=%08X\n", k, e);
            }
        }
        fprintf(stderr, "\n[GUEST FAULT] sig=%d host=%p guest=0x%08llx cur_func=0x%08X\n",
            sig, si->si_addr, (unsigned long long)guest, g_cur_func);
        uint64_t *x = uc->uc_mcontext->__ss.__x;
        fprintf(stderr, "  live x19=%llx x20=%llx x21=%llx x22=%llx x23=%llx x24=%llx x25=%llx x26=%llx x27=%llx x28=%llx lr=%llx\n",
            (unsigned long long)x[19], (unsigned long long)x[20], (unsigned long long)x[21],
            (unsigned long long)x[22], (unsigned long long)x[23], (unsigned long long)x[24],
            (unsigned long long)x[25], (unsigned long long)x[26], (unsigned long long)x[27],
            (unsigned long long)x[28], (unsigned long long)uc->uc_mcontext->__ss.__lr);
        fprintf(stderr, "  eax=%08X ecx=%08X edx=%08X ebx=%08X\n", g_eax, g_ecx, g_edx, g_ebx);
        fprintf(stderr, "  esp=%08X ebp=%08X esi=%08X edi=%08X\n", g_esp, g_ebp, g_esi, g_edi);
        {   /* WinMain stack: args + CRT-startup frame area */
            uint32_t esp_g = g_esp & 0xFFFFFFFFu;
            unsigned char *sp = (unsigned char *)hle_ptr(esp_g);
            if (sp) {
                for (unsigned off = 0x1B70u; off < 0x1C00u; off += 16) {
                    uint32_t *row = (uint32_t *)(sp + off);
                    fprintf(stderr, "  [esp+%03X @ %08X] %08X %08X %08X %08X\n",
                            off, esp_g + off, row[0], row[1], row[2], row[3]);
                }
            }
        }
        {   /* config-string pool at fault */
            unsigned char *pool = (unsigned char *)hle_ptr(0x653020u);
            if (pool) {
                fprintf(stderr, "  [pool @ 653020]");
                for (int j = 0; j < 96; j++) fprintf(stderr, " %02X", pool[j]);
                fprintf(stderr, "\n");
            }
        }
        uint32_t regs[4] = { g_ecx, g_esi, g_edi, g_ebx };
        const char* names[4] = { "ecx", "esi", "edi", "ebx" };
        for (int k = 0; k < 4; k++) {
            uint32_t va = regs[k];
            unsigned char *p = (unsigned char *)hle_ptr(va);
            if (!p || va < 0x400000u || va >= 0x78A000u) continue;
            fprintf(stderr, "  [%s @ %08X]", names[k], va);
            for (int j = 0; j < 64; j++) fprintf(stderr, " %02X", p[j]);
            fprintf(stderr, "\n");
        }
    }
    exit(139);
}

extern void (*hle_on_exit)(int code);
static void dump_on_exit(int code) { (void)code; recomp_dump_trace("hle_exit"); }

/* ---- [aoe2_re] headless driver: run without a window (nothing on the
 * desktop, no mouse grab), drive input from a FIFO, dump frames as BMPs.
 * Commands, one per line:  move x y | down x y | up x y | click x y |
 * rdown/rclick x y | key VK | kdown/kup VK | shot PATH | quit  (guest/game coordinates, e.g. 800x600). ---- */
#define WM_LBUTTONDOWN_ 0x0201u
#define WM_LBUTTONUP_   0x0202u
#define WM_RBUTTONDOWN_ 0x0204u
#define WM_RBUTTONUP_   0x0205u
#define WM_MOUSEMOVE_   0x0200u

static int   drv_fifo_fd = -1;
static FILE *drv_fifo_fp;
static char  drv_fifo_path[512];
static char  drv_shot_dir[512];
static int   drv_shot_every;                             /* seconds between auto-shots, 0 off */
static unsigned drv_shot_n;
static uint32_t drv_last_shot;
static int   drv_exit;

static void drv_dump_frame(const char *path) {
    const uint8_t *px; const uint32_t *pal;
    int w, h, pitch, bpp; unsigned seq;
    if (!hle_dd_frame(&px, &w, &h, &pitch, &bpp, &pal, &seq)) {
        fprintf(stderr, "[driver] shot %s: no frame yet\n", path);
        return;
    }
    SDL_Surface *s = SDL_CreateRGBSurfaceFrom((void *)px, w, h, 8, pitch, 0, 0, 0, 0);
    if (!s) { fprintf(stderr, "[driver] surface: %s\n", SDL_GetError()); return; }
    if (pal) {
        SDL_Color c[256];
        for (int i = 0; i < 256; i++) { c[i].r = (uint8_t)pal[i]; c[i].g = (uint8_t)(pal[i] >> 8); c[i].b = (uint8_t)(pal[i] >> 16); c[i].a = 255; }
        SDL_SetPaletteColors(s->format->palette, c, 0, 256);
    }
    if (SDL_SaveBMP(s, path) != 0) fprintf(stderr, "[driver] save %s: %s\n", path, SDL_GetError());
    else fprintf(stderr, "[driver] shot %s\n", path);
    SDL_FreeSurface(s);
}

static void drv_shot_auto(void) {
    if (!drv_shot_dir[0] || !drv_shot_every) return;
    uint32_t now = hle_ticks_ms();
    if (drv_last_shot && now - drv_last_shot < (uint32_t)drv_shot_every * 1000u) return;
    drv_last_shot = now;
    char path[600];
    snprintf(path, sizeof path, "%s/frame_%04u.bmp", drv_shot_dir, drv_shot_n++);
    drv_dump_frame(path);
}

static void drv_frame_shot(const uint8_t *px, int w, int h, int pitch, int bpp) {
    (void)px; (void)w; (void)h; (void)pitch; (void)bpp;
    drv_shot_auto();
}

static void drv_command(char *line) {
    while (*line == ' ') line++;
    size_t n = strlen(line);
    while (n && (line[n - 1] == '\n' || line[n - 1] == '\r' || line[n - 1] == ' ')) line[--n] = 0;
    if (!n || *line == '#') return;
    unsigned x, y, vk;
    char arg[400];
    if (sscanf(line, "move %u %u", &x, &y) == 2) hle_input_mouse(WM_MOUSEMOVE_, (int)x, (int)y);
    else if (sscanf(line, "down %u %u", &x, &y) == 2) hle_input_mouse(WM_LBUTTONDOWN_, (int)x, (int)y);
    else if (sscanf(line, "up %u %u", &x, &y) == 2) hle_input_mouse(WM_LBUTTONUP_, (int)x, (int)y);
    else if (sscanf(line, "rdown %u %u", &x, &y) == 2) hle_input_mouse(WM_RBUTTONDOWN_, (int)x, (int)y);
    else if (sscanf(line, "rup %u %u", &x, &y) == 2) hle_input_mouse(WM_RBUTTONUP_, (int)x, (int)y);
    else if (sscanf(line, "rclick %u %u", &x, &y) == 2) {
        hle_input_mouse(WM_RBUTTONDOWN_, (int)x, (int)y);
        hle_input_mouse(WM_RBUTTONUP_, (int)x, (int)y);
    }
    else if (sscanf(line, "click %u %u", &x, &y) == 2) {
        hle_input_mouse(WM_LBUTTONDOWN_, (int)x, (int)y);
        hle_input_mouse(WM_LBUTTONUP_, (int)x, (int)y);
    } else if (sscanf(line, "key %u", &vk) == 1) {
        hle_input_key(1, vk, 0); hle_input_key(0, vk, 0);
    } else if (sscanf(line, "kdown %u", &vk) == 1) hle_input_key(1, vk, 0);
    else if (sscanf(line, "kup %u", &vk) == 1) hle_input_key(0, vk, 0);
    else if (sscanf(line, "shot %400s", arg) == 1) drv_dump_frame(arg);
    else if (!strcmp(line, "quit")) drv_exit = 1;
    else fprintf(stderr, "[driver] ? %s\n", line);
}

static void drv_poll(void) {
    if (drv_fifo_path[0] && drv_fifo_fd < 0) {
        drv_fifo_fd = open(drv_fifo_path, O_RDONLY | O_NONBLOCK);
        if (drv_fifo_fd >= 0) drv_fifo_fp = fdopen(drv_fifo_fd, "r");
    }
    if (drv_fifo_fd >= 0) {
        char *line = NULL; size_t cap = 0;
        ssize_t got;
        while ((got = getline(&line, &cap, drv_fifo_fp)) >= 0) drv_command(line);
        free(line);
        if (got < 0 && errno != EAGAIN) {                   /* all writers closed: reopen next pump */
            fclose(drv_fifo_fp); drv_fifo_fd = -1;
        } else if (got < 0) { clearerr(drv_fifo_fp); }
    }
    drv_shot_auto();
    if (drv_exit) exit(0);
}

int main(int argc, char** argv) {
    hle_on_exit = dump_on_exit;
    struct sigaction sa;
    sa.sa_sigaction = fault_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGBUS, &sa, 0);
    sigaction(SIGSEGV, &sa, 0);

    /* aoe shims first: hle_resolve takes the first registration of a name,
     * so these override win32hle's built-ins (VERSION.dll, for one) */
    win32hle_register(win32hle_aoe);
    recomp_host_init();
    {   /* [aoe2_re] give the guest a real Windows-style command line: the
     * CRT parses it for the exe path; the default "game.exe" leaves the
     * startup's module-name register NULL. */
        extern void hle_set_command_line(const char* cmdline);
        char cl[600];
        const char* aoe = "C:" "\\" "AOE" "\\" "game.exe";
        snprintf(cl, sizeof cl, "%s", aoe);
        hle_set_command_line(cl);
    }
    /* pull --calltrace/--firsthit/... out of argv before the boot path sees them */
    for (int i = 1; i < argc; i++) {
        int used = recomp_trace_arg(argc, argv, i);
        if (used > 0) { i += used - 1; }
    }
    {   /* [aoe2_re] open the SDL screen. --headless: no window at all (the
     * desktop is untouched); input then comes from the --input FIFO and
     * frames go to --shots DIR every --shot-every SECONDS. --bg: a window,
     * but the mouse is never grabbed. */
        extern int hle_screen_open(const char* title, int fullscreen, int headless);
        int headless = 0, grab = 1;
        const char *input_fifo = NULL, *shots_dir = NULL;
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "--headless")) headless = 1;
            else if (!strcmp(argv[i], "--bg")) grab = 0;
            else if (!strcmp(argv[i], "--input") && i + 1 < argc) input_fifo = argv[++i];
            else if (!strcmp(argv[i], "--shots") && i + 2 < argc) { shots_dir = argv[++i]; drv_shot_every = atoi(argv[++i]); }
        }
        if (!grab) { extern void hle_screen_confine(int on); hle_screen_confine(0); }
        if (headless) {
            hle_screen_poll_hook = drv_poll;
            hle_screen_frame_hook = drv_frame_shot;
            if (input_fifo) {
                snprintf(drv_fifo_path, sizeof drv_fifo_path, "%s", input_fifo);
                unlink(drv_fifo_path);
                if (mkfifo(drv_fifo_path, 0600) != 0 && errno != EEXIST)
                    fprintf(stderr, "[driver] mkfifo %s: %s\n", drv_fifo_path, strerror(errno));
            }
            if (shots_dir) {
                snprintf(drv_shot_dir, sizeof drv_shot_dir, "%s", shots_dir);
                if (mkdir(drv_shot_dir, 0755) != 0 && errno != EEXIST)
                    fprintf(stderr, "[driver] mkdir %s: %s\n", drv_shot_dir, strerror(errno));
            }
            fprintf(stderr, "[driver] headless: input=%s shots=%s/%ds\n",
                    drv_fifo_path[0] ? drv_fifo_path : "-", drv_shot_dir[0] ? drv_shot_dir : "-", drv_shot_every);
        }
        if (hle_screen_open("Age of Empires II", 0, headless) != 0)
            fprintf(stderr, "[aoe2_re] screen open failed\n");
    }
    const char* exe = getenv("AOE_BIN");
    if (!exe || !*exe) exe = "reference/AOE2.EXE";
    int rc = recomp_host_boot_permissive(exe);
    fprintf(stderr, "permissive boot rc=%d (0=clean)\n", rc);
    if (rc == 0) {
        uint32_t r = recomp_host_run();
        recomp_dump_trace("after recomp_host_run");
        fprintf(stderr, "guest returned 0x%08X\n", r);
    }
    return 0;
}
