// Reconstruction of reference-executable sub_40A3E0 (VA 0x40A3E0, 0x1A bytes).
// Identity: thiscall method decrementing a countdown counter at this+0x88.
//
// Differential-verified against the original x86 (Scripts/fnmatch.py):
//   --the field is decremented FIRST and stored unclamped;
//   --the clamp-to-0 write only happens when the NEW value is negative;
//   --the RETURN VALUE is the raw decremented value (can be negative even
//     though the stored field clamps to 0). A naive
//     "if (--v < 0) v = 0; return v;" reconstruction would diverge.
typedef int BOOL;  // not used here; method returns int

struct CountdownObj {
    unsigned char pad[0x88];
    int counter;  // +0x88
};

extern "C" int __thiscall countdown_tick(CountdownObj* self)
{
    // mov eax, [ecx+88h]; dec eax; mov [ecx+88h], eax
    const int result = --self->counter;
    // jns skip: only when the new value is negative is the field re-stored as 0
    if (result < 0)
        self->counter = 0;
    return result;
}
