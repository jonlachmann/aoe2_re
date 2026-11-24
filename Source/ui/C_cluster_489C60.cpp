#include "C_cluster_489C60.hpp"

// 0x489EE0 — factorA * factorB + addend; the fourth argument is unused.
MATCH_FUNC(0x489EE0)
double C_cluster_489C60::MultiplyAdd_489EE0(float addend, float factorA,
                                            float factorB, int unused)
{
    (void)unused;
    return factorA * factorB + addend;
}
