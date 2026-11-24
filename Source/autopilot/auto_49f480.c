
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_49f480(_DWORD *self, int a2)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(a2 + 12) = self[4];
  self[4] = a2;
  ++self[8];
  return result;
}
