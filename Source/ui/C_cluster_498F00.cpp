// C_cluster_498F00 — the 0x498F00 UI cluster. The 0x4998B0 entry dispatches on
// its first argument (0x1C, 0x113, 0x3B9) and drives the +0x240/+0x24C/
// +0x260/+0x264/+0x270 state block.
#include "Function.hpp"

class C_cluster_498F00 {
public:
    char pad_00[0x104];
    unsigned char field_104;      // +0x104 state byte
    char pad_105[0x128 - 0x105];
    unsigned char field_128;      // +0x128 one-shot byte
    char pad_129[0x24c - 0x129];
    int field_24c;                // +0x24C counter
    char pad_250[0x25c - 0x250];
    int field_25c;                // +0x25C
    int field_260;                // +0x260
    int field_264;                // +0x264
    char pad_268[0x270 - 0x268];
    int field_270;                // +0x270 gate
    void M_4999B0();
    void M_499760();
    void M_4995B0();
    void M_499510();
    int M_4998B0(int a1, int a2, int a3, int a4);
};

// 0x4998B0 — four-argument entry dispatcher. For 0x1C: when a3 is nonzero and
// +0x264/+0x260 are set, run 0x4995B0 and clear both; when a3 is zero and
// +0x264 is clear, run 0x499510 and set both. For 0x113: run 0x499760 when
// +0x270 is set. For 0x3B9: only when the +0x104 state byte is 1 or 2, decrement
// the +0x24C counter, and when it reaches 0 with +0x25C clear, clear +0x128 for
// state 1 and run 0x4999B0. Everything else returns 0.
MATCH_FUNC(0x4998B0)
int C_cluster_498F00::M_4998B0(int a1, int a2, int a3, int a4)
{
    switch (a2)
    {
    case 0x1c:
    {
        if (a3 != 0)
        {
            if (field_264 == 0)
                break;
            if (field_260 == 0)
                break;
            M_4995B0();
            field_260 = 0;
            field_264 = 0;
            return 0;
        }
        if (field_264 != 0)
            break;
        M_499510();
        field_260 = 1;
        field_264 = 1;
        break;
    }
    case 0x113:
    {
        if (field_270 == 0)
            break;
        M_499760();
        return 0;
    }
    case 0x3b9:
    {
        unsigned char state = field_104;
        if (state != 1 && state != 2)
            break;
        if (field_24c > 0)
            field_24c--;
        if (field_24c != 0)
            break;
        if (field_25c != 0)
            break;
        if (state == 1)
            field_128 = 0;
        M_4999B0();
        return 0;
    }
    }
    return 0;
}

