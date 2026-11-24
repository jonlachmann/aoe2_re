
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4b8c30(_DWORD *self, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  self[67] = a2;
  self[68] = a3;
  self[69] = a4;
  result = a6;
  self[70] = a5;
  self[71] = a6;
  return result;
}
