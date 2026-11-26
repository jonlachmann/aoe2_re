// Native probe for the matched-only build path. Links byte-verified C++ bodies
// compiled by the host compiler (not the lifted recomp_*.c and not VC6 objects)
// and exercises their recovered semantics on host-allocated instances.
#include <cstdio>
#include <cstdlib>

#include "app/C_cluster_405790.hpp"
#include "app/C_cluster_40F0C0.hpp"

int main()
{
    int failures = 0;

    C_cluster_405790* a = (C_cluster_405790*)calloc(1, sizeof(C_cluster_405790));
    a->Init_405790(123);
    if (a->field_4 != 123) { printf("405790 field_4 %d != 123\n", a->field_4); failures++; }
    if (a->field_8 != 0) { printf("405790 field_8 %d != 0\n", a->field_8); failures++; }
    if (a->vtbl_0 != (void*)0x61cab4) { printf("405790 vtbl_0 %p != 0x61cab4\n", a->vtbl_0); failures++; }

    C_cluster_40F0C0* b = (C_cluster_40F0C0*)calloc(1, sizeof(C_cluster_40F0C0));
    b->field_EA4 = 0x32;
    if (!b->Check_40F4B0()) { printf("40F4B0 true expected at 0x32\n"); failures++; }
    b->field_EA4 = 0x31;
    if (b->Check_40F4B0()) { printf("40F4B0 false expected at 0x31\n"); failures++; }

    printf("probe: %d failures\n", failures);
    return failures != 0;
}
