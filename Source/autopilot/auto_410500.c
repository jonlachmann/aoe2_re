
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_410500(_DWORD *self)
{
  int result; // eax

  self[self[937] + 938] = self[120];
  result = self[937] + 1;
  self[937] = result;
  return result;
}
