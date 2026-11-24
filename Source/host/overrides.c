/* [aoe2_re] Overrides of lifted functions (agent_plan.md step 2).
 *
 * Every lifted definition is compiled weak (Scripts/build_boot.sh marks
 * `^void sub_` in a shadow copy), so a strong `sub_XXXXXXXX` here wins at
 * link time: the dispatch table, recomp_funcs.h declarations and every
 * direct RECOMP_CALL site bind to the override.
 *
 * An override runs inside the lifted model, exactly like a win32hle shim:
 * on entry g_esp points at [ret][arg0][arg1]...; read args with A32/APTR/
 * ASTR, leave the result in eax, and pop what the original's `ret` popped
 * (RET(value, argc) pops ret + argc*4 - for a caller-pops (cdecl) original
 * use RET(value, 0)). All guest registers are caller-saved in this model
 * (RECOMP_REGS_OUT/IN around every call), so an override may clobber them,
 * but it must preserve nothing except the contract above.
 *
 * Each override is verified against the lifted function it replaces before
 * the original is retired (Scripts/diffharness.py, difftest in refs/pcrecomp).
 */
#include "win32hle.h"
#include <zlib.h>


/* ---- sub_005ED91B: the deflate decoder entry (host zlib) ----
 * The game's decoder is an x86 coroutine: on input-dry or output-full it copies
 * the guest stack into a 0xAD90-byte state block and resumes by jumping to a
 * saved return address. Those addresses are placeholders in a lift, so the
 * resume path lands with a lost state pointer (the random-map load faulted at
 * 0x8207 in sub_005ED4F6). This host does the whole stream, keeping the same
 * contract so the callers are untouched:
 *
 *   int inflate(in, in_off, &in_len, out, out_off, &out_len, state, final)
 *   cdecl; in_len/out_len come back as consumed/produced. 0: call again
 *   (input used up or output full); -1: stream end; -2: corrupt.
 *
 * state is the guest 0xAD90 block; +0xA958 is the resume index, 0 when the
 * stream is fresh. A guest VA is made a host address through ADDR because
 * this model maps the image at RECOMP_MEM_BASE. */
#define INFLATE_RESUME 0xA958u
#define INFLATE_STREAMS 16
static struct { uint32_t state; z_stream z; int live; } g_iz[INFLATE_STREAMS];

static z_stream* iz_for(uint32_t state) {
    int k = -1;
    for (int i = 0; i < INFLATE_STREAMS; i++)
        if (g_iz[i].live && g_iz[i].state == state) { k = i; break; }
    if (k >= 0 && MEM32(state + INFLATE_RESUME) != 0) return &g_iz[k].z;
    if (k < 0)
        for (int i = 0; i < INFLATE_STREAMS; i++)
            if (!g_iz[i].live) { k = i; break; }
    if (k < 0) k = (int)(state >> 4) % INFLATE_STREAMS;
    if (g_iz[k].live) inflateEnd(&g_iz[k].z);
    memset(&g_iz[k], 0, sizeof g_iz[k]);
    if (inflateInit2(&g_iz[k].z, -15) != Z_OK) return NULL;
    g_iz[k].live = 1;
    g_iz[k].state = state;
    MEM32(state + INFLATE_RESUME) = 1;
    return &g_iz[k].z;
}

void sub_005ED91B(void) {
    uint32_t a[8];
    for (int i = 0; i < 8; i++) a[i] = MEM32(g_esp + 4u + 4u * (uint32_t)i);
    uint32_t in = a[0] + a[1];
    uint32_t in_len = MEM32(a[2]);
    uint32_t out = a[3] + a[4];
    uint32_t out_len = MEM32(a[5]);
    z_stream* z = iz_for(a[6]);
    int r = -2;
    if (z) {
        z->next_in = (Bytef *)ADDR(in);
        z->avail_in = in_len;
        z->next_out = (Bytef *)ADDR(out);
        z->avail_out = out_len;
        int s = inflate(z, Z_NO_FLUSH);
        MEM32(a[2]) = in_len - z->avail_in;
        MEM32(a[5]) = out_len - z->avail_out;
        r = s == Z_STREAM_END ? -1 : (s == Z_OK || s == Z_BUF_ERROR) ? 0 : -2;
        if (r == -2) fprintf(stderr, "[inflate] state 0x%08X: corrupt stream (%d)\n", a[6], s);
    }
    RET((uint32_t)r, 0);
}

/* ---- sub_465270: the DirectX version check (pilot override) ----
 * The original asks DirectPlay for the DirectX version: DirectPlayCreate,
 * QueryInterface(IID_IDirectPlay4) + Release, then GetModuleHandleA("dplayx")
 * -> GetModuleFileNameA -> GetFileVersionInfoSizeA/GetFileVersionInfoA ->
 * VerQueryValueA("\\") and tests the dplayx file version >= 4.06.03.0516.
 * It takes no arguments and returns nonzero (in eax, al really) when the
 * installed DirectX is new enough. The pilot answers "yes" unconditionally,
 * which retires the DirectPlay and VERSION emulation from aoe_shims.c. */
void sub_00465270(void) { RET(1, 0); }

/* ---- sub_41F0C0: local install-media validation used when starting a game ----
 * The original samples a drive's media (its arg chooses which check): a
 * global validity flag short-circuits true, else it finds a drive letter,
 * asks GetDriveTypeA for a device type and compares the volume label. The
 * HLE filesystem is a fixed disk, so the check failed. The development
 * override treats the local installation layout as present and retires the
 * platform media query for this path. The original pops one argument (ret 4). */
void sub_0041F0C0(void) { RET(1, 1); }
