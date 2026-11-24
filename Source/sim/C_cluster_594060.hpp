// C_cluster_594060 — this-edge cluster attached to C_vt61DA40 members.
// Partial layout: 0x594E70 takes the object as an explicit argument rather
// than through this, and only writes a dword flag at +8.
#pragma once

#include "Function.hpp"

class C_cluster_594060 {
public:
    int SetFlag_594E70(int object);
};
