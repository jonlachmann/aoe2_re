// Portable guest-VA access layer for matched bodies.
//
// Under VC6 the macro is a plain pointer cast from the 32-bit guest VA, which
// is exactly what the original binary does; codegen is unchanged and bodies
// stay byte-exact. Under the native matched-only build (MATCHED_NATIVE), the
// same VA is offset by the host-side guest image base, so a 32-bit guest VA
// stored in a field/global can be dereferenced on a 64-bit host.
#pragma once

#if defined(MATCHED_NATIVE)
extern "C" long g_matched_base;   // host address of guest VA 0
#define ADDR(va) ((void*)((unsigned long)(unsigned int)(va) + (unsigned long)g_matched_base))
#else
#define ADDR(va) ((void*)(unsigned long)(va))
#endif
