
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

bool __thiscall auto_433e50(int self)
{
  return *(_BYTE *)(self + 24) && (*(_DWORD *)(*(_DWORD *)(self + 20) + 4) & 2) != 0;
}
