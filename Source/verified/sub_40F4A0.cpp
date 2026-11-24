// sub_40F4A0 (VA 0x40F4A0, 0x0E bytes) — thiscall
// BOOL f(): this[937] == 0
extern "C" int __thiscall sub_40F4A0(void* self)
{
    unsigned* fields = static_cast<unsigned*>(self);
    return fields[937] == 0 ? 1 : 0;
}
