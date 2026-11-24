
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4b6c30(_DWORD *self, int a2, int a3, int a4)
{
  int result; // eax

  self[201] = a2;
  result = a4;
  self[202] = a3;
  self[203] = a4;
  return result;
}
