// sub_40E2A0 (VA 0x40E2A0, 0x10 bytes) — thiscall
// int f(): word at (this[10]+8), or -1 if this[10]==0
extern "C" int __thiscall sub_40E2A0(void* self)
{
    unsigned* fields = static_cast<unsigned*>(self);
    unsigned p = fields[10];
    if (!p)
        return -1;
    return *reinterpret_cast<short*>(p + 8);
}
