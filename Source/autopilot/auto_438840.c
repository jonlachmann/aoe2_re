
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

unsigned int __thiscall auto_438840(_DWORD *self, int a2, int a3)
{
  unsigned int result; // eax

  self[20 * a2 + 145 + self[144]] = a3;
  result = self[144] + 1;
  self[144] = result;
  if ( result >= 0x14 )
    self[144] = 0;
  return result;
}
