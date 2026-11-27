#include "C_pnl_scbr.hpp"

extern int (__cdecl *g_61C3C8)();

// 0x4B8CC0 — slot +0x4C scrollbar tick dispatcher. Read the +0x158 mode:
// mode 1 jumps to the one-shot handler at the end; any other mode but 2
// returns 0. In mode 2, bail when +0x14C is clear, then compare the tick delta
// since +0x15C against +0x160 (unsigned) and store the new tick. Switch on
// (+0x148 - 1): case 0 and 1 run the 0x4B93B0 service with (0,0)/(1,0); case 3
// maps the +0x198 rectangle (M_4A1D50(+0x150,+0x154,&+0x198)) and runs
// 0x4B93B0(2,0) on success, else clears +0x14C/+0x158 and dispatches slot 8;
// case 4 does the same for +0x1A8 with 0x4B93B0(3,0). All cases return 0; the
// mode-1 handler compares the delta since +0x15C against +0x164, sets mode 2
// and +0x15C = tick - +0x160, then falls into the shared return.
MATCH_FUNC(0x4B8CC0)
int C_pnl_scbr::M_4B8CC0()
{
    int state = *(unsigned char*)((char*)this + 0x158);
    switch (state)
    {
    case 2:
        {
            int z = 0;
            if (field_14c == 0)
                break;
            int t = g_61C3C8();
            if ((unsigned int)(t - field_15c) < (unsigned int)field_160)
                break;
            field_15c = t;
            switch (*(unsigned char*)((char*)this + 0x148) - 1)
            {
            case 0:
                M_4B93B0(z, z);
                return 0;
            case 1:
                M_4B93B0(1, z);
                return 0;
            case 3:
                if (M_4A1D50(field_150, field_154, (char*)this + 0x198) == 0)
                {
                    field_14c = z;
                    *(unsigned char*)((char*)this + 0x158) = (unsigned char)z;
                    slot_008(1);
                }
                else
                    M_4B93B0(2, z);
                return 0;
            case 4:
                if (M_4A1D50(field_150, field_154, (char*)this + 0x1a8) == 0)
                {
                    field_14c = z;
                    *(unsigned char*)((char*)this + 0x158) = (unsigned char)z;
                    slot_008(1);
                }
                else
                    M_4B93B0(3, z);
                return 0;
            }
        }
        break;
    case 1:
        {
            int t = g_61C3C8();
            if ((unsigned int)(t - field_15c) < (unsigned int)field_164)
                break;
            int span = field_160;
            *(unsigned char*)((char*)this + 0x158) = 2;
            field_15c = t - span;
        }
        break;
    }
    return 0;
}
