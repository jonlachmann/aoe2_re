// Native execution probe over matched bodies that read guest globals. The
// globals are initialized from the reference binary's data image, so values
// like g_61c598=1.0, g_61c584=0.0 and g_61dd2c=FLT_MAX come from the original
// process, not from appended defaults.
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "game/C_vt61E328.hpp"
#include "gfx/C_vt61DA40.hpp"

int main()
{
    int failures = 0;

    C_vt61E328* e = (C_vt61E328*)calloc(1, sizeof(C_vt61E328));
    float f = e->Get_434BE0(0);
    if (f != 1.0f) { printf("Get_434BE0 %f != 1.0\n", f); failures++; }

    e->field_168 = 1;
    if (e->M_435810() != 0) { printf("M_435810 expect 0 above 0.0\n"); failures++; }
    e->field_168 = -1;
    if (e->M_435810() != 1) { printf("M_435810 expect 1 below 0.0\n"); failures++; }

    C_vt61DA40* d = (C_vt61DA40*)calloc(1, sizeof(C_vt61DA40));
    float m = d->Get_41A090(0, 0, 0);
    if (m != 3.4028234663852886e+38f) { printf("Get_41A090 %f != FLT_MAX\n", m); failures++; }

    printf("globals exec probe: %d failures\n", failures);
    return failures != 0;
}
