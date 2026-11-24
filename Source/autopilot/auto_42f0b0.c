
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_42f0b0(_DWORD *self, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  int result; // eax

  v5 = self + 1207;
  *v5 = a2;
  result = a4;
  v5[1] = a3;
  v5[2] = a4;
  v5[3] = a5;
  return result;
}
