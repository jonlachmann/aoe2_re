// sub_40F4B0 (VA 0x40F4B0, 0x0F bytes) — thiscall
// BOOL f(): this[937] == 50
extern "C" int __thiscall sub_40F4B0(void* self)
{
    unsigned* fields = static_cast<unsigned*>(self);
    return fields[937] == 50 ? 1 : 0;
}
