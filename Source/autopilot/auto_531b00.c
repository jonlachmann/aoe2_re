
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_531b00(_DWORD *self)
{
  int result; // eax

  result = self[9];
  if ( result )
    return *(_DWORD *)(result + 4) - self[126];
  return result;
}
