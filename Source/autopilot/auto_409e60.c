
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_409e60(_DWORD *self)
{
  _DWORD *result; // eax

  result = self;
  *(_BYTE *)self = 0;
  self[1] = 0;
  *((_BYTE *)self + 8) = 0;
  *((_BYTE *)self + 9) = 0;
  *((_BYTE *)self + 10) = 0;
  *((_BYTE *)self + 11) = 0;
  return result;
}
