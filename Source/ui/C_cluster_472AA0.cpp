#include "C_cluster_472AA0.hpp"
#include "matched_mem.h"

MATCH_FUNC(0x472AA0)
C_cluster_472AA0* C_cluster_472AA0::Init_472AA0(int a1, int a2)
{
    *(void**)this = (void*)0x620b74;
    M_472B00();
    this->Hook_472B20(a1, a2);
    return this;
}

// 0x472B20 — load the player object's HKI data. Ask the 0x6645C4 app
// (409A10) for the current player index, take its +0x1C game-settings object
// (464FF0) for the player number, and when valid build "player%d_%d"/"player%d"
// in Buffer. Replace the +0x14 in-object name through the matched 499C40,
// build "%s%s.hki" in FileName from the prefix (default 0x662BE0) and that name,
// open through the matched 4BE760(FileName,0x8000), feed the handle to 472C10
// and release the file through 4BE860. Returns 0 on any failure, 1 on success.
// WIP: every failure path shares one epilogue, and the original lays that block
// first then the success block; this translation puts them in the opposite
// order, so ours is 240 vs 227 bytes although the branches and calls match.
extern void* g_6645c4;
extern char __cdecl sub_5FCE14(char* dst, char* fmt, ...);
extern void __cdecl sub_499C40(void** a1, char* a2);
extern int __cdecl sub_4BE760(int a1, int a2);
extern int __cdecl sub_4BE860(int a1);
class C_vt61C62C {
public:
    int M_409A10();
};
class T464FD0 {
public:
    int index_0;              // +0x00
    char pad_04[0x08 - 0x04];
    char** items_8;           // +0x08
    int M_464FF0();
};
class T472C10 {
public:
    char Other_472C10(int a1);
};

WIP_FUNC(0x472B20)
char C_cluster_472AA0::Hook_472B20(int a1, int a2)
{
    char Buffer[256];
    char FileName[256];
    int v4;
    T464FD0* v5;
    int v6;
    char* v7;
    char* v8;
    int v9;
    v4 = ((C_vt61C62C*)g_6645c4)->M_409A10();
    v5 = *(T464FD0**)((char*)g_6645c4 + 0x1c);
    if (v5 == 0)
        goto fail;
    v6 = v5->M_464FF0();
    if (v6 < 1)
        goto fail;
    if (v4 > 0)
        sub_5FCE14(Buffer, (char*)ADDR(0x652d78), v4, v6);
    else
        sub_5FCE14(Buffer, (char*)ADDR(0x652d6c), v6);
    sub_499C40((void**)&field_14, Buffer);
    v7 = field_14;
    if (v7 == 0)
        goto fail;
    v8 = (char*)a2;
    if (v8 == 0)
        v8 = (char*)ADDR(0x662be0);
    sub_5FCE14(FileName, (char*)ADDR(0x652d60), v8, v7);
    v9 = sub_4BE760((int)FileName, 0x8000);
    if (v9 <= -1)
        goto fail;
    ((T472C10*)this)->Other_472C10(v9);
    sub_4BE860(v9);
    return 1;
fail:
    return 0;
}

MATCH_FUNC(0x472B00)
void C_cluster_472AA0::M_472B00()
{
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_4 = 0;
}
