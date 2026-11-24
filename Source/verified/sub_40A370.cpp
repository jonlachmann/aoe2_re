// sub_40A370 (VA 0x40A370, 0x1E bytes) — thiscall
// int f(int idx): returns this[idx+37] (1-based dword select), -1 if idx not in {1,2}
extern "C" int __thiscall sub_40A370(void* self, int idx)
{
    int* fields = static_cast<int*>(self);
    if (idx < 1 || idx > 2)
        return -1;
    return fields[idx + 36];
}
