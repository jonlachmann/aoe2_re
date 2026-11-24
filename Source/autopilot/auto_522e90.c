
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_522e90(_DWORD *self)
{
  int result; // eax

  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[8] = self[7];
  result = self[14] + 1;
  self[14] = result;
  return result;
}
