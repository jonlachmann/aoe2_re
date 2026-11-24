
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4af4b0(_DWORD *self, __int16 a2, int a3, int a4)
{
  int result; // eax

  result = a2;
  self[a2 + 62] = a3;
  self[a2 + 71] = a4;
  return result;
}
