#include "C_pnl_txt.hpp"

// Draw-surface hooks (the TDrawArea methods 0x45FE50/0x45FEA0 are matched in
// Source/gfx/draw_area.cpp but that class has no shared header yet).
class TDrawAreaHooks {
public:
    int GetDC_45FE50(int unused);
    void ReleaseDC_45FEA0(int unused);
};

extern void (__stdcall *cv_61c06c)(int a1, int a2);
extern int (__stdcall *cv_61C038)(void* a1, int a2);
extern void (__stdcall *cv_61C074)(int a1, int a2);

// 0x4BC260 — slot 12 (pnl_txt::draw). Zero the +0x38 result; return when the
// +0x20 surface, +0x70 or +0x6C gates are clear. Otherwise run slot 10 and the
// +0x4BC360 background, take the surface DC (0x653874 marker), and when the DC
// is valid bind it (+0x8C), save the +0x108 mapping, then iterate the
// +0x100..+0x102 index range: when (+0x74 and +0x78) or +0x68 is set, dispatch
// slot 69 (4BC750) with the DC, row counter and 1, otherwise with 0. Restore the
// DC mapping, unbind, release the DC, then run +0x4BC560 and slot 11.
MATCH_FUNC(0x4BC260)
void C_pnl_txt::draw_4BC260()
{
    int i = 0;
    field_38 = 0;
    if (field_20 == 0)
        return;
    if (field_70 == 0)
        return;
    if (field_6c == 0)
        return;
    slot_010(i);
    M_4BC360();
    int dc = ((TDrawAreaHooks*)field_20)->GetDC_45FE50(0x653874);
    if (dc != 0)
    {
        cv_61c06c(dc, field_8c);
        int saved = cv_61C038((void*)dc, field_108);
        cv_61C074(dc, 1);
        short bx = field_100;
        while (bx <= field_102)
        {
            if ((field_74 != 0 && field_78 != 0) || field_68 != 0)
                slot_069(dc, i, bx, 1);
            else
                slot_069(dc, i, bx, 0);
            bx++;
            i++;
        }
        cv_61C038((void*)dc, saved);
        cv_61c06c(dc, 0);
        ((TDrawAreaHooks*)field_20)->ReleaseDC_45FEA0(0x653874);
    }
    M_4BC560();
    slot_011();
}
