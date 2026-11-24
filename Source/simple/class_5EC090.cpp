#include "Function.hpp"

class S5EC090 {
public:
    char pad_00[0x408];
    int** array_408;
    unsigned char Get_5EC090(int byte_index, int row_index);
};

MATCH_FUNC(0x5EC090)
unsigned char S5EC090::Get_5EC090(int byte_index, int row_index)
{
    int* row = array_408[row_index];
    return ((unsigned char*)row)[byte_index];
}
