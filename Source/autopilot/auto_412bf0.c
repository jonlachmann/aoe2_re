
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_412bf0(_DWORD *self, int a2)
{
  int result; // eax

  result = self[12];
  self[21] = result;
  self[12] = a2;
  return result;
}
