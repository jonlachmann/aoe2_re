// Native guest-image probe: map the PE data range, sync the generated g_*
// arrays from it, then verify symbol contents equal image contents at the same
// guest VAs and that ADDR() is idempotent for image-backed pointers.
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "matched_guest_image.h"
#include "matched_mem.h"

extern char g_61C000[0x1000];
extern char g_6645c4[0x1000];
extern char g_vt_62AAE0[0x1000];

static int checkEqual(const char* label, char* sym, unsigned va)
{
    char* img = (char*)ADDR(va);
    if (memcmp(sym, img, 0x40) != 0)
    {
        printf("%s contents differ from image at 0x%x\n", label, va);
        return 1;
    }
    return 0;
}

int main()
{
    const char* pe = getenv("AOE_BIN");
    int failures = 0;

    if (pe == 0 || LoadGuestImage(pe) != 0)
    {
        printf("guest image load failed\n");
        return 1;
    }
    SyncGuestGlobals();

    failures += checkEqual("g_61C000", g_61C000, 0x61C000);
    failures += checkEqual("g_6645c4", g_6645c4, 0x6645C4);
    failures += checkEqual("g_vt_62AAE0", g_vt_62AAE0, 0x62AAE0);

    // ADDR must leave a pointer already inside the image unchanged.
    void* p = ADDR(0x61C000);
    void* q = ADDR_impl(p);
    if (p != q)
    {
        printf("ADDR not idempotent on image pointer\n");
        failures++;
    }

    printf("guest image probe: %d failures (VA 0x61C000 -> %p, image %ld bytes)\n",
           failures, p, (long)g_matched_image_size);
    return failures != 0;
}
