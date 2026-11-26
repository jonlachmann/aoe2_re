// C_cluster_49F630 — ui cluster anchored at 0x49F630.
// 0x49F650 inserts a 0x0C-byte node into the circular list headed at +0x14
// after a name lookup misses; 0x49FA50 walks that same list by name bytes.
#pragma once

#include "Function.hpp"

// Object whose +0x1C holds the name pointer compared by the 0x49FA50 scanner.
class T49F650Key {
public:
    char pad_00[0x1c];
    int Get_4A2060();             // unresolved accessor at 0x4A2060
    void SetIndex_5BE8D0(int v);  // unresolved owner setter at 0x5BE8D0
};

// Circular doubly-linked node: key at +0x00, previous at +0x04, next at +0x08.
struct S49FA50Node {
    int field_0;                  // +0x00 object pointer
    S49FA50Node* field_4;         // +0x04 previous node
    S49FA50Node* field_8;         // +0x08 next node
};

class C_cluster_49F630 {
public:
    char pad_00[0x14];            // +0x00..+0x14
    S49FA50Node* head_14;         // +0x14 circular list head
    int count_18;                 // +0x18 node count

    int M_49FA50(int name);
    void Hook_49FB00(int a1, int a2); // unresolved switch at 0x49FB00
    int M_49F650(T49F650Key* key, int a2, int a3);
};
