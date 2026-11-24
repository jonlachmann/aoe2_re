#include "Function.hpp"

extern unsigned char g_75fdc4;
MATCH_FUNC(0x5BB230)
unsigned char* Clear_5BB230()
{
    g_75fdc4 = 0;
    return &g_75fdc4;
}

extern int g_66e3fc;
MATCH_FUNC(0x48BD10)
void Clear_48BD10()
{
    g_66e3fc = 0;
}

class S52BC00 {
public:
    S52BC00* Init_52BC00();
};
MATCH_FUNC(0x52BC00)
S52BC00* S52BC00::Init_52BC00()
{
    *(int*)((char*)this) = 0;
    return this;
}

extern int g_740b54[];
MATCH_FUNC(0x54F1C0)
void Set_54F1C0(int index, int value)
{
    if (index >= 1 && index <= 0x100)
        g_740b54[index] = value;
}

extern int g_741b58[];
MATCH_FUNC(0x54F1E0)
void Set_54F1E0(int index)
{
    if (index >= 0 && index < 0x100)
        g_741b58[index] = 1;
}

extern int g_741758[];
MATCH_FUNC(0x54DDE0)
void Zero_54DDE0(int unused, int index)
{
    if (index >= 0 && index < 0x100)
        g_741758[index] = 0;
}
