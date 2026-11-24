
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_40a3e0(_DWORD *self)
{
  int result; // eax

  result = self[34] - 1;
  self[34] = result;
  if ( result < 0 )
    self[34] = 0;
  return result;
}
