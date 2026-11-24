
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5b08f0(_DWORD *self)
{
  _DWORD *result; // eax

  result = self;
  *self = -1;
  self[1] = -1;
  self[2] = -1;
  self[3] = -1;
  self[4] = -1;
  return result;
}
