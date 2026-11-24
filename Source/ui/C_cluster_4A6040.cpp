#include "C_cluster_4A6040.hpp"

MATCH_FUNC(0x514400)
unsigned char C_cluster_4A6040::Get_514400()
{
    return *(unsigned char*)((char*)this + 0x900);
}
