#include "Function.hpp"

class S48B530 {
public:
    char pad_00[0xc4];
    void Init_48B530();
};

class S410410 {
public:
    char pad_00[0xea4];
    int field_ea4;
    int array_ea8[0x100];
    int field_1e0;
    void Pop_410410();
};

class S493780 {
public:
    int count;
    char pad_04[8];
    int* array_0c;
    void Reset_493780();
};

class S522E10Node {
public:
    S522E10Node* next_0;
    S522E10Node* prev_4;
};

class S522E10 {
public:
    char pad_00[0x10];
    S522E10Node* head_10;
    char pad_14[0xc];
    int count_20;
    void Add_522E10(S522E10Node* node);
};
MATCH_FUNC(0x522E10)
void S522E10::Add_522E10(S522E10Node* node)
{
    node->next_0 = head_10;
    node->prev_4 = 0;
    head_10 = node;
    ++count_20;
}

class S537D70 {
public:
    char pad_00[0x1a0];
    int field_1a0;
    int Pop_537D70();
};
