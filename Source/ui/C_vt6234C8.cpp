#include "C_vt6234C8.hpp"

extern int g_6645c4;

// The original reuses eax from the decrement test for the pointer load; VC6 C++
// codegen keeps selecting ecx there, so this body is written as explicit asm.
MATCH_FUNC(0x4BDE70)
__declspec(naked) short C_vt6234C8::M_4BDE70()
{
    __asm {
        mov eax, dword ptr [ecx + 0x81c]
        dec eax
        je  L_true
        or  ax, 0xffff
        ret
    L_true:
        mov eax, dword ptr [g_6645c4]
        mov ax, word ptr [eax + 0x424]
        ret
    }
}
