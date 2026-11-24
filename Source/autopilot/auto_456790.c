
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_456790(int *self, int a2)
{
  int result; // eax
  int *i; // edx

  result = 0;
  for ( i = self + 728; *i > 0; ++i )
  {
    if ( ++result >= 150 )
      return result;
  }
  self[result + 728] = a2;
  return result;
}
