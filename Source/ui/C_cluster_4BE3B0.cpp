#include "C_cluster_4BE3B0.hpp"

extern T4BE3B0Node* g_73facc;

// 0x4BE3B0 — walk the 0x73FACC node list and search each node's record entry
// table for a1 then each entry's relative sub-array for a2. Outputs start at
// -1/0; a hit writes node keys, entry/sub-entry fields and returns 1.
WIP_FUNC(0x4BE3B0)
int __cdecl sub_4BE3B0(int a1, int a2, int* a3, int* a4, int* a5, int* a6)
{
    *a3 = -1;
    *a4 = 0;
    *a5 = 0;
    *a6 = 0;

    T4BE3B0Node* node = g_73facc;
    if (node == 0)
        return 0;

    do
    {
        T4BE3B0Record* rec = node->field_8;
        if (rec->field_38 > 0)
        {
            for (int i = 0; i < rec->field_38; i++)
            {
                T4BE3B0Entry* ent = rec->field_40 + i;
                if (ent->field_0 == a1)
                {
                    int* sub = (int*)((char*)rec + ent->field_4);
                    if (ent->field_8 > 0)
                    {
                        for (int k = 0; k < ent->field_8; k++)
                        {
                            if (*sub == a2)
                            {
                                *a3 = node->field_4;
                                *a4 = sub[1];
                                *a5 = node->field_0;
                                *a6 = sub[2];
                                return 1;
                            }
                            sub = (int*)((char*)sub + 0xc);
                        }
                    }
                }
            }
        }
        node = node->next_c;
    } while (node != 0);

    return 0;
}
