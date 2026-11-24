#include "Function.hpp"

extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hwnd, char* text);

class S4213B0 {
public:
    char pad_00[0x28];
    void* field_28;
    char pad_2c[0x430 - 0x2c];
    char text_430[0x100];
    void SetText_4213B0();
};

