// Clipped horizontal span fill on a draw surface (the software font renderer's
// glyph path — see docs/bringup_log.md). Field names are provisional until the
// owning class is decompiled.
#include <string.h>
#include <stdlib.h>
#include "Function.hpp"

// Display-surface driver object (field_3C / field_0 of TDrawArea): a vtable
// pointer at +0 and a type tag byte at +0x3C.
struct DDVtbl {
    char pad_00[0x44];
    int (__stdcall *fn_44)(void* self, int* out);       // +0x44 GetDC
    char pad_48[0x64 - 0x48];
    int (__stdcall *fn_64)(void* self, int arg1, void* desc, int flags, int event);  // +0x64 Lock
    int (__stdcall *fn_68)(void* self, int dc);         // +0x68 ReleaseDC
    char pad_6C[0x74 - 0x6C];
    int (__stdcall *fn_74)(void* self, int entry, void* entries);  // +0x74 SetColorKey
    char pad_78[0x80 - 0x78];
    int (__stdcall *fn_80)(void* self, void* bits);     // +0x80 Unlock
};
struct DDObj {
    DDVtbl* lpVtbl;           // +0x00
    char pad_04[0x3C - 0x04];
    unsigned char type_3C;    // +0x3C
};

// Clip-span builder allocated by TDrawArea::SetClipBounds_460740 (0x68 bytes,
// ctor 0x522EB0, dtor 0x522F90, helpers 0x522FF0/0x523060/0x5230F0). The
// methods are out of line in the binary; only the shape is needed here.
class TClipSpan {
public:
    char pad_00[0x50];
    int field_50;               // +0x50 height the span was built for
    char pad_54[0x68 - 0x54];

    TClipSpan(int w, int h);
    ~TClipSpan();
    void Begin_523060();
    void SetRect_522FF0(int l, int t, int r, int b);
    void ClipSpan_5230F0(int l, int r, int y);
};

class TDrawArea {
public:
    DDObj* field_0;           // 0x00  display surface object (type tag at [obj+0x3c])
    char pad_04[0x08 - 0x04];
    unsigned char* Bits;      // 0x08
    int* field_C;             // 0x0C  descriptor block ([blk+4] gets the pitch)
    char pad_10[0x18 - 0x10];
    int Width;                // 0x18
    int Height;               // 0x1C
    int Pitch;                // 0x20
    int Orientation;          // 0x24  1 = top-down rows, else bottom-up
    int ClipLeft;             // 0x28
    int ClipTop;              // 0x2C
    int ClipRight;            // 0x30
    int ClipBottom;           // 0x34
    int field_38;             // 0x38  cached DC, for a GDI draw area (type 1)
    DDObj* field_3C;          // 0x3C  secondary surface object
    char field_40[0x50 - 0x40];  // 0x40  DDSURFACEDESC filled by Lock
    int field_50;             // 0x50  desc lpPitch
    char pad_54[0x64 - 0x54];
    unsigned char* field_64;  // 0x64  desc lpSurface (the locked pixel pointer)
    char pad_68[0xA8 - 0x68];
    unsigned long field_A8;   // 0xA8  status flags (bit 0x800 tested)
    char pad_AC[0xB4 - 0xAC];
    unsigned char* field_B4;  // 0xB4  row-pointer base mirrored from Bits
    char pad_B8[0xBC - 0xB8];
    int* field_BC;            // 0xBC  cached row-pointer array (Height entries)
    int* field_C0;            // 0xC0  copy of the active row-pointer array
    int* field_C4;            // 0xC4  rotated row-pointer array
    int field_C8;             // 0xC8  value from Set_461B40
    TClipSpan* field_CC;      // 0xCC  clip-span builder (see SetClipBounds_460740)
    TClipSpan* field_D0;      // 0xD0  copy of field_CC
    int field_D4;             // 0xD4  last dx
    int field_D8;             // 0xD8  last dy
    int field_DC;             // 0xDC  byte size of field_BC
    int field_E0;             // 0xE0  byte size of field_C4
    char pad_E4[0xE8 - 0xE4];
    int field_E8;             // 0xE8  0/1 flag set from field_A8 bit 0x800
    int field_EC;             // 0xEC  display mode / palette id
    char pad_F0[0xF8 - 0xF0];
    int field_F8;             // 0xF8  row-rotation enable
    unsigned char field_FC;   // 0xFC  palette-bpp or flag byte

    void BuildRowPtrs_460490();
    void SetMode_460EC0(int mode, unsigned char flag);
    void SetClipRect_460660(const int* rect);
    void SetClipBounds_460740(int left, int top, int right, int bottom);
    int Lock_45FD90(int unused, int flags);
    int GetDC_45FE50(int unused);
    void Unlock_45FE10(int unused);
    void ReleaseDC_45FEA0(int unused);
    void Set_461B40(int v);
    void CopyPalette_461C70(int* dest);

    void RotateRowPtrs_460570(int dx, int dy);
    void UpdatePitch_460620();
    int GetPitch_460650();
    void SetPixel_460F20(int x, int y, int color);
    unsigned char* GetPixelPtr_460F80(int x, int y);
    void FrameRect_461130(int x0, int y0, int x1, int y1, int color);
    void HLine_461370(int x, int y, int len, int color);
    void VLine_461400(int x, int y, int len, int color);
    void FillRect_461490(int x0, int y0, int x1, int y1, int color);
};


// Records the display mode in field_EC; a zero mode resets field_FC to 0xff,
// otherwise the driver object is told the new 8-bit palette index.
// Looks like DirectDraw: fn_74 is IDirectDrawSurface::SetColorKey(DDCKEY_SRCBLT,
// &DDCOLORKEY{flag, flag}).
// WIP: differs only in the 3 failure jumps (je/je/jne at +0x20/+0x26/+0x30).
// The original lays out [main path, call, exit, 0xff block + dup'd exit] and
// they hit the exit right after the call. Ours always puts the exit block last,
// after the 0xff block, so they jump to +0x59. Tried, all give the same 3
// bytes: if/else either way round, early returns, goto either way, switch,
// do/while(0)+break, while/for, nested or || guards, an inline helper, a real
// COM virtual. Not the compiler: SP3 (c2.dll 12.00.8447, the rich header's
// version) gives the same 3 bytes for every variant.
WIP_FUNC(0x460EC0)
void TDrawArea::SetMode_460EC0(int mode, unsigned char flag)
{
    field_EC = mode;
    if (mode) {
        field_FC = flag;
        if (field_3C && field_0 && field_0->type_3C == 2) {
            int entries[2];
            entries[0] = flag;
            entries[1] = flag;
            field_3C->lpVtbl->fn_74(field_3C, 8, entries);
        }
    } else
        field_FC = 0xff;
}

// Locks the draw area's pixels for drawing. A type-1 GDI driver or an already
// locked area returns Bits; a missing secondary surface returns 0. The Lock
// goes through the secondary surface's vtable slot +0x64 and fills the
// DDSURFACEDESC at +0x40 (its lpSurface at +0x64 becomes Bits). Then the
// pitch/row pointers are refreshed.
MATCH_FUNC(0x45FD90)
int TDrawArea::Lock_45FD90(int unused, int flags)
{
    (void)unused;
    if (!(field_0 != 0 && field_0->type_3C == 1)) {
        if (field_3C == 0)
            return 0;
        if (Bits != 0)
            return (int)Bits;
        if (field_38 != 0)
            return 0;
        // Two call sites, not one call with `flags != 0`: VC6 cross-jumps the
        // identical tails, leaving only `push 1` / `push 0` in the arms. A single
        // call with a 0/1 argument becomes setne instead.
        int r;
        if (flags != 0)
            r = field_3C->lpVtbl->fn_64(field_3C, 0, field_40, 1, 0);
        else
            r = field_3C->lpVtbl->fn_64(field_3C, 0, field_40, 0, 0);
        if (r != 0)
            return 0;
        Bits = field_64;
        UpdatePitch_460620();
        if (Bits != field_B4)
            BuildRowPtrs_460490();
    }
    return (int)Bits;
}

// Unlocks the draw area's pixel buffer: releases the Lock (secondary-surface
// vtable slot +0x80) and clears Bits. The type-1 GDI path and a lockless area
// do nothing.
MATCH_FUNC(0x45FE10)
void TDrawArea::Unlock_45FE10(int unused)
{
    (void)unused;
    if (field_0 == 0 || field_0->type_3C != 1) {
        if (field_3C != 0 && Bits != 0) {
            field_3C->lpVtbl->fn_80(field_3C, Bits);
            Bits = 0;
        }
    }
}

// Releases the HDC a GetDC call left at +0x38 (secondary-surface vtable slot
// +0x68 = ReleaseDC). The type-1 GDI path and a no-DC area do nothing.
MATCH_FUNC(0x45FEA0)
void TDrawArea::ReleaseDC_45FEA0(int unused)
{
    (void)unused;
    if (field_0 == 0 || field_0->type_3C != 1) {
        if (field_3C != 0 && field_38 != 0) {
            field_3C->lpVtbl->fn_68(field_3C, field_38);
            field_38 = 0;
        }
    }
}

// Gets an HDC for text drawing on this area (used by pnl_btn/pnl_txt GDI text).
// A type-1 driver (a GDI draw area) returns its cached HDC at +0x38; otherwise
// the secondary surface (field_3C) gets the DC through its vtable slot +0x44.
// A locked pixel buffer (Bits) means software drawing, so no HDC (0).
MATCH_FUNC(0x45FE50)
int TDrawArea::GetDC_45FE50(int unused)
{
    (void)unused;
    if (field_0 != 0 && field_0->type_3C == 1)
        return field_38;
    if (field_3C == 0)
        return 0;
    if (field_38 == 0) {
        if (Bits != 0)
            return 0;
        field_3C->lpVtbl->fn_44(field_3C, &field_38);
        return field_38;
    }
    return field_38;
}

// Stores one dword at +0xC8 (a mode/index setter). No calls.
MATCH_FUNC(0x461B40)
void TDrawArea::Set_461B40(int v)
{
    field_C8 = v;
}

// Copies 256 dwords from [(driver object +0xb8) + 4*i] to dest[4*i].
MATCH_FUNC(0x461C70)
void TDrawArea::CopyPalette_461C70(int* dest)
{
    for (int i = 0; i < 256; i++)
        dest[i] = ((int*)((char*)field_0 + 0xb8))[i];
}

// (Re)builds the row-pointer table field_BC from Bits: entry i is the start
// of row i, honoring Orientation and field_F8. Refreshes the rotated copy.
MATCH_FUNC(0x460490)
void TDrawArea::BuildRowPtrs_460490()
{
    int size = Height * 4;
    if (size != field_DC) {
        if (field_BC)
            free(field_BC);
        field_BC = (int*)malloc(size);
        field_DC = size;
        field_C0 = field_BC;
    }
    unsigned char* row;
    int step;
    if (Orientation == 1 || field_F8 != 0) {
        if (field_F8 == 0)
            row = Bits;
        else
            row = Bits + Pitch * 5;
        step = Pitch;
        if (field_F8 != 0)
            step = Width;
    } else {
        row = Bits + (Height - 1) * Pitch;
        step = -Pitch;
    }
    for (int i = 0; i < Height; i++) {
        field_BC[i] = (int)row;
        row += step;
    }
    if (field_C4 != 0)
        RotateRowPtrs_460570(field_D4, field_D8);
    field_B4 = Bits;
}

// Rebuilds the rotated row-pointer array (field_C4) from the cached row table
// (field_BC): entry i becomes src[(dy+i) wrapped] + dx. Remembers dx/dy in
// field_D4/field_D8.
MATCH_FUNC(0x460570)
void TDrawArea::RotateRowPtrs_460570(int dx, int dy)
{
    int size = Height * 4;
    if (size == 0 || !field_F8)
        return;
    if (dx < 0 || dy < 0)
        return;
    if (size != field_E0) {
        if (field_C4)
            free(field_C4);
        field_C4 = (int*)malloc(size);
        field_E0 = size;
    }
    int row = dy;
    for (int i = 0; i < Height; i++) {
        field_C4[i] = field_BC[row] + dx;
        row++;
        if (row >= Height)
            row = 0;
    }
    field_D4 = dx;
    field_D8 = dy;
    field_C0 = field_C4;
}

// Copies the pending pitch (field_50) into Pitch and the descriptor block,
// then records in field_E8 whether bit 0x800 of the status word is clear.
MATCH_FUNC(0x460620)
void TDrawArea::UpdatePitch_460620()
{
    Pitch = field_50;
    field_C[1] = Pitch;
    if (field_A8 & 0x800) {
        field_E8 = 0;
        return;
    }
    field_E8 = 1;
}

MATCH_FUNC(0x460650)
int TDrawArea::GetPitch_460650()
{
    return Pitch;
}

// Copies a clip rect (4 dwords: l, t, r, b) into the clip fields, clamping
// each axis to the surface; a null rect selects the whole surface. Then
// hands the bounds to SetClipBounds_460740.
MATCH_FUNC(0x460660)
void TDrawArea::SetClipRect_460660(const int* rect)
{
    if (rect != 0) {
        ClipLeft = rect[0];
        ClipTop = rect[1];
        ClipRight = rect[2];
        ClipBottom = rect[3];
        if (ClipLeft < 0)
            ClipLeft = 0;
        else if (ClipLeft > Width - 1)
            ClipLeft = Width - 1;
        if (ClipRight < 0)
            ClipRight = 0;
        else if (ClipRight > Width - 1)
            ClipRight = Width - 1;
        if (ClipTop < 0)
            ClipTop = 0;
        else if (ClipTop > Height - 1)
            ClipTop = Height - 1;
        if (ClipBottom < 0)
            ClipBottom = 0;
        else if (ClipBottom > Height - 1)
            ClipBottom = Height - 1;
        if (ClipRight < ClipLeft) {
            int t = ClipRight;
            ClipRight = ClipLeft;
            ClipLeft = t;
        }
        if (ClipBottom < ClipTop) {
            int t = ClipBottom;
            ClipBottom = ClipTop;
            ClipTop = t;
        }
    } else {
        ClipLeft = 0;
        ClipTop = 0;
        ClipRight = Width - 1;
        ClipBottom = Height - 1;
    }
    SetClipBounds_460740(ClipLeft, ClipTop, ClipRight, ClipBottom);
}

// Stores the (already clamped) clip bounds, rebuilds the clip-span object when
// the surface height changed (delete + new), then re-initialises it and clips
// every row in the band. The EH frame and state variable come from `new
// TClipSpan`: the memory must be freed if the ctor throws, and only /GX makes
// VC6 emit that frame.
//
// WIP: 310/310 bytes, same instructions; only the registers VC6 picks for the
// call-argument preloads differ (a free-register "rotation phase"). Original
// vs ours: first temp field_50->eax vs ecx; ctor args Height/W -> ecx,edx vs
// edx,ecx; SetRect args bottom/right/top/left -> eax,ecx,edx,eax vs
// edx,eax,ecx,edx; loop ClipSpan right/left -> ecx,edx vs eax,ecx; tail1
// field_CC -> eax vs edx; tail2 -> ecx vs eax (and the original schedules
// `pop edi` before the field_D0 store, so its fs restore reads [esp+4]).
// Tried, all leave the phase: operand order (Height != field->field_50 both
// ways; swap fixes load order only), for/++y/while/do-while loop forms
// (identical output), nested ifs, `if (!field_CC)`, local TClipSpan* copies
// (worse), moving definitions into address order (no effect), the full SP3
// VC98 tree (c2.dll 12.00.8447 - identical output to SP5). Struct/layout and
// callees verified against the asm; only allocation differs.
WIP_FUNC(0x460740)
void TDrawArea::SetClipBounds_460740(int left, int top, int right, int bottom)
{    ClipLeft = left;
    ClipTop = top;
    ClipRight = right;
    ClipBottom = bottom;
    if (field_CC != 0 && Height != field_CC->field_50) {
        delete field_CC;
        field_CC = 0;
    }
    if (field_CC == 0)
        field_CC = new TClipSpan(Width, Height);
    field_CC->Begin_523060();
    field_CC->SetRect_522FF0(ClipLeft, ClipTop, ClipRight, ClipBottom);
    for (int y = ClipTop; y <= ClipBottom; y++)
        field_CC->ClipSpan_5230F0(ClipLeft, ClipRight, y);
    field_D0 = field_CC;

}


// Writes one clipped pixel. Returns void.
MATCH_FUNC(0x460F20)
void TDrawArea::SetPixel_460F20(int x, int y, int color)
{
    if (!Bits)
        return;
    if (x < ClipLeft || x > ClipRight)
        return;
    if (y < ClipTop || y > ClipBottom)
        return;
    if (Orientation == 1)
        Bits[Pitch * y + x] = (unsigned char)color;
    else
        Bits[(Height - y - 1) * Pitch + x] = (unsigned char)color;
}

// Address of pixel (x, y), or 0 when the surface has no bits.
MATCH_FUNC(0x460F80)
unsigned char* TDrawArea::GetPixelPtr_460F80(int x, int y)
{
    if (!Bits)
        return 0;
    if (Orientation == 1)
        return Bits + Pitch * y + x;
    return Bits + (Height - y - 1) * Pitch + x;
}

// Strokes the outline of the rectangle (x0,y0)-(x1,y1) inclusive; the corner
// coordinates are swapped so x0/y0 are the top-left. Returns void.
MATCH_FUNC(0x461130)
void TDrawArea::FrameRect_461130(int x0, int y0, int x1, int y1, int color)
{
    if (x0 > x1) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y0 > y1) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }
    int w = x1 - x0 + 1;
    if (w < 1)
        return;
    int h = y1 - y0 + 1;
    if (h < 1)
        return;
    HLine_461370(x0, y0, w, color);
    HLine_461370(x0, y1, w, color);
    VLine_461400(x0, y0, h, color);
    VLine_461400(x1, y0, h, color);
}

// Fills `len` pixels of `color` on row y from column x, clipped to
// [ClipLeft,ClipRight]x[ClipTop,ClipBottom]. Returns void: the eax the original
// leaves behind is memset's result or clip-test garbage.
MATCH_FUNC(0x461370)
void TDrawArea::HLine_461370(int x, int y, int len, int color)
{
    if (!Bits)
        return;
    if (x > ClipRight)
        return;
    if (y < ClipTop || y > ClipBottom)
        return;
    if (x < ClipLeft) {
        len += x - ClipLeft;
        x = ClipLeft;
    }
    if (x + len - 1 > ClipRight)
        len = ClipRight - x + 1;
    if (len < 1)
        return;
    unsigned char* p;
    if (Orientation == 1)
        p = Bits + Pitch * y + x;
    else
        p = Bits + (Height - y - 1) * Pitch + x;
    memset(p, (unsigned char)color, len);
}

// Fills `len` pixels of `color` down column x from row y, clipped to
// [ClipLeft,ClipRight]x[ClipTop,ClipBottom]. Returns void.
MATCH_FUNC(0x461400)
void TDrawArea::VLine_461400(int x, int y, int len, int color)
{
    if (!Bits)
        return;
    if (x < ClipLeft || x > ClipRight)
        return;
    if (y > ClipBottom)
        return;
    if (y < ClipTop) {
        len += y - ClipTop;
        y = ClipTop;
    }
    if (y + len - 1 > ClipBottom)
        len = ClipBottom - y + 1;
    if (len < 1)
        return;
    int step;
    unsigned char* p;
    if (Orientation == 1) {
        p = Bits + Pitch * y + x;
        step = Pitch;
    } else {
        p = Bits + (Height - y - 1) * Pitch + x;
        step = -Pitch;
    }
    while (len > 0) {
        *p = (unsigned char)color;
        p += step;
        len--;
    }
}

// Fills the (sorted) rectangle (x0,y0)-(x1,y1) inclusive with `color`, clipped
// to the clip rectangle. One memset per row; row order follows Orientation.
//
// WIP: ours 224 bytes vs original 242. Same checks/order, but (a) the same
// free-register rotation phase as SetClipBounds_460740: the arg preloads land
// in x0->ebp vs ebx, y0->ebx vs edi, ClipTop->edi vs ebp; (b) the loop lacks
// the original's entry `jmp` over the width reload: the original keeps w in
// edx through the orientation branch, jumps to the first memset with edx, and
// reloads w from [esp+0x18] only on later iterations (0xd6), while ours
// reloads into eax every iteration at the loop head (that stub is the 18-byte
// size gap). Tried: do/while (240 bytes, h gets spilled, worse registers),
// for with a separate counter, function-scope `int t`. /GX on or off gives the
// identical body here (no EH in this function). Callees (memset 0x5FE3A0)
// verified; only allocation/layout differs.
WIP_FUNC(0x461490)
void TDrawArea::FillRect_461490(int x0, int y0, int x1, int y1, int color)
{    if (!Bits)
        return;
    if (x0 > x1) {
        int t = x0;
        x0 = x1;
        x1 = t;
    }
    if (y0 > y1) {
        int t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x0 > ClipRight || x1 < ClipLeft || y0 > ClipBottom || y1 < ClipTop)
        return;
    if (x0 < ClipLeft)
        x0 = ClipLeft;
    if (x1 > ClipRight)
        x1 = ClipRight;
    if (y0 < ClipTop)
        y0 = ClipTop;
    if (y1 > ClipBottom)
        y1 = ClipBottom;
    int w = x1 - x0 + 1;
    int h = y1 - y0 + 1;
    if (w < 1)
        return;
    if (h < 1)
        return;
    int step;
    unsigned char* p;
    if (Orientation == 1) {
        step = Pitch;
        p = Bits + Pitch * y0 + x0;
    } else {
        step = -Pitch;
        p = Bits + (Height - y0 - 1) * Pitch + x0;
    }
    for (; h > 0; h--) {
        memset(p, (unsigned char)color, w);
        p += step;
    }

}
