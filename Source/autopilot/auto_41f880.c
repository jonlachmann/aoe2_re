
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41f880(_DWORD *self, int a2)
{
  int result; // eax
  _DWORD *i; // ecx

  result = 0;
  for ( i = self + 633; a2 != *i; ++i )
  {
    if ( ++result >= 9 )
      return -1;
  }
  return result;
}
