
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5bec40(_DWORD *self, int a2)
{
  int result; // eax

  result = self[1];
  if ( result == 8 || result == 9 )
  {
    if ( self[16] == a2 )
      self[16] = -1;
    result = self[16];
    if ( result > a2 )
      self[16] = --result;
  }
  return result;
}
