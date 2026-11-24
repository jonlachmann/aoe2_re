
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c1410(_DWORD *self, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 )
  {
    if ( a2 > 16 )
      result = 15;
    self[4917] = result;
  }
  else
  {
    result = 0;
    self[4917] = 0;
  }
  return result;
}
