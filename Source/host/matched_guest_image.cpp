#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matched_guest_image.h"

extern "C" char* g_matched_image = 0;
extern "C" long g_matched_image_size = 0;
extern "C" long g_matched_base = 0;

static const unsigned GUEST_IMAGE_VA = 0x400000;
static const unsigned GUEST_IMAGE_LEN = 0x400000;   // covers 0x400000..0x800000

static unsigned get32(const unsigned char* p)
{
    return (unsigned)p[0] | ((unsigned)p[1] << 8) |
           ((unsigned)p[2] << 16) | ((unsigned)p[3] << 24);
}

// Minimal PE32 reader: map the whole guest data range and copy each section's
// raw bytes to its virtual address. Header parse failures return -1.
extern "C" int LoadGuestImage(const char* path)
{
    FILE* f = fopen(path, "rb");
    if (f == 0)
        return -1;
    unsigned char* raw = (unsigned char*)malloc(0x1000000);
    if (raw == 0) { fclose(f); return -1; }
    size_t n = fread(raw, 1, 0x1000000, f);
    fclose(f);

    if (n < 0x100 || raw[0] != 'M' || raw[1] != 'Z')
    { free(raw); return -1; }

    unsigned pe = get32(raw + 0x3C);
    if (pe + 0x100 > n || get32(raw + pe) != 0x00004550)
    { free(raw); return -1; }

    unsigned sectable = pe + 24 + (unsigned)(raw[pe + 20] | (raw[pe + 21] << 8));
    unsigned base = get32(raw + pe + 24 + 28);        // PE32 ImageBase
    unsigned numsects = raw[pe + 6] | (raw[pe + 7] << 8);

    char* img = (char*)malloc(GUEST_IMAGE_LEN);
    if (img == 0) { free(raw); return -1; }
    memset(img, 0, GUEST_IMAGE_LEN);

    for (unsigned i = 0; i < numsects; i++)
    {
        const unsigned char* s = raw + sectable + i * 40;
        unsigned va = get32(s + 12);
        unsigned vsize = get32(s + 8);
        unsigned rsize = get32(s + 16);
        unsigned rptr = get32(s + 20);
        if (va < GUEST_IMAGE_VA || va >= GUEST_IMAGE_VA + GUEST_IMAGE_LEN)
            continue;
        unsigned off = va - GUEST_IMAGE_VA;
        unsigned len = vsize < rsize ? vsize : rsize;
        if (off + len > GUEST_IMAGE_LEN)
            len = GUEST_IMAGE_LEN - off;
        if (rptr + len <= n)
            memcpy(img + off, raw + rptr, len);
    }

    g_matched_image = img;
    g_matched_image_size = GUEST_IMAGE_LEN;
    g_matched_base = (long)img - (long)GUEST_IMAGE_VA;
    free(raw);
    return 0;
}
