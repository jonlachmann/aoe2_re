
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

unsigned int __thiscall auto_5ea290(_DWORD *self, unsigned int a2)
{
  unsigned int result; // eax

  result = self[70];
  if ( result >= a2 )
  {
    result -= a2;
    self[70] = result;
  }
  else
  {
    self[70] = 0;
  }
  return result;
}
