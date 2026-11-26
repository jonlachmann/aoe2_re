// Portable guest-VA access layer for matched bodies.
//
// Under VC6 the macro is a plain pointer cast from the 32-bit guest VA, which
// is exactly what the original binary does; codegen is unchanged and bodies
// stay byte-exact. Under the native matched-only build (MATCHED_NATIVE), the
// same VA is offset by the host-side guest image base, so a 32-bit guest VA
// stored in a field/global can be dereferenced on a 64-bit host. A pointer
// that already lies inside the mapped guest image is returned unchanged,
// making ADDR idempotent for image-backed pointers.
#pragma once

#if defined(MATCHED_NATIVE)
extern "C" long g_matched_base;   // host address of guest VA 0
extern "C" char* g_matched_image;
extern "C" long g_matched_image_size;

inline void* ADDR_impl(void* p)
{
    char* im = g_matched_image;
    if (im != 0 && (char*)p >= im && (char*)p < im + g_matched_image_size)
        return p;
    return (void*)((unsigned long)(unsigned int)(unsigned long)p + (unsigned long)g_matched_base);
}
#define ADDR(va) ADDR_impl((void*)(unsigned long)(unsigned int)(unsigned long)(va))
#else
#define ADDR(va) ((void*)(unsigned long)(va))
#endif
