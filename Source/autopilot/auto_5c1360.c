
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c1360(_DWORD *self, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 )
  {
    if ( a2 > 1 )
      result = 1;
    self[4915] = result;
  }
  else
  {
    result = 0;
    self[4915] = 0;
  }
  return result;
}
