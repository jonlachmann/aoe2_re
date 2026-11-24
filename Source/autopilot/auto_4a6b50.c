
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4a6b50(_DWORD *self, int a2, int a3)
{
  int result; // eax

  result = a2;
  self[1] = a2;
  self[2] = a3;
  return result;
}
