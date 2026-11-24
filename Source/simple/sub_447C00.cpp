#include "Function.hpp"

// sub_447C00 (VA 0x447C00, 0xF bytes) - cdecl: calls the method on the global
// object at 0x66EA48 with the global address 0x652304 as its argument.
class G447C {
public:
    void Method_49F960(void* p);
};
extern G447C g_66EA48;
extern int g_652304;

MATCH_FUNC(0x447C00)
extern "C" void __cdecl sub_447C00()
{
    g_66EA48.Method_49F960(&g_652304);
}
