#include "C_vt623E50.hpp"

MATCH_FUNC(0x4CD410)
__declspec(naked) int C_vt623E50::M_4CD410()
{
    __asm {
        push edi
        mov edi, dword ptr [ecx + 0x10]
        test edi, edi
        je  L_none
        or  ecx, -1
        xor eax, eax
        repne scasb
        not ecx
        pop edi
        lea eax, [ecx + 0xc]
        ret
    L_none:
        xor eax, eax
        pop edi
        mov eax, 0xc
        ret
    }
}
