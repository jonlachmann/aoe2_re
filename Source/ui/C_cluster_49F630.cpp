#include "C_cluster_49F630.hpp"
#pragma intrinsic(strcmp)

extern void* __cdecl sub_5F8FF0(unsigned int a1, int a2);

// 0x49F650 — when the 0x49FA50 name scan misses, allocate a 0x0C-byte node,
// record the key object, register it through 0x5BE8D0(0) and splice it into
// the circular list at +0x14 (previous/next pair around the head) before
// bumping the +0x18 count; then, when the second argument is set, hand the key
// and third argument to 0x49FB00. Returns 0 only when the allocation fails.
MATCH_FUNC(0x49F650)
int C_cluster_49F630::M_49F650(T49F650Key* key, int a2, int a3)
{
    int name = ((T49F650Key*)key)->Get_4A2060();
    if (M_49FA50(name) == 0)
    {
        S49FA50Node* n = (S49FA50Node*)sub_5F8FF0(1, 0xC);
        if (n == 0)
            return 0;
        n->field_0 = (int)key;
        key->SetIndex_5BE8D0(0);
        n->field_4 = head_14->field_4;
        n->field_8 = head_14;
        head_14->field_4 = n;
        n->field_4->field_8 = n;
        count_18 = 1 + count_18;
    }
    if (a2 != 0)
        Hook_49FB00((int)key, a3);
    return 1;
}

// 0x49FA50 — walk the +0x14 circular list comparing node names to the given
// string via inline strcmp; a NULL input, an empty list or a list without a
// matching node returns 0, and a matching node is re-checked and returned.
// 0x5BE8D0 is code-folded in the binary: three classes alias that one body.
// These PE-named forwarding methods bind their callers to the matched
// S5BE940::SetIndex_5BE8D0 code instead of a host stub. They live in this TU
// (not the owner) so the gate's per-object suffix lookup stays unambiguous.
class S5BE940 {
public:
    void SetIndex_5BE8D0(int index);
};
class T49FB00Obj {
public:
    void SetIndex_5BE8D0(int index);
};
class C_global_66EA48 {
public:
    void Hook_5BE8D0(int index);
};

void T49F650Key::SetIndex_5BE8D0(int index)
{
    ((S5BE940*)this)->SetIndex_5BE8D0(index);
}
void T49FB00Obj::SetIndex_5BE8D0(int index)
{
    ((S5BE940*)this)->SetIndex_5BE8D0(index);
}
void C_global_66EA48::Hook_5BE8D0(int index)
{
    ((S5BE940*)this)->SetIndex_5BE8D0(index);
}

MATCH_FUNC(0x49FA50)
int C_cluster_49F630::M_49FA50(int name)
{
    if (name == 0)
        return 0;
    S49FA50Node* n = head_14->field_8;
    while (n != head_14)
    {
        if (strcmp((char*)((T49F650Key*)n->field_0)->Get_4A2060(), (char*)name) == 0)
            break;
        n = n->field_8;
    }
    if (n != head_14 &&
        strcmp((char*)((T49F650Key*)n->field_0)->Get_4A2060(), (char*)name) == 0)
        return (int)n;
    return 0;
}
#pragma function(strcmp)
