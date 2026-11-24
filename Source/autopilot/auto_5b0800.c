
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5b0800(_DWORD *self)
{
  _DWORD *result; // eax

  result = self;
  self[1] = -1;
  self[2] = -1;
  self[3] = -1;
  *(_BYTE *)self = -1;
  self[4] = -1082130432;
  self[5] = -1082130432;
  self[6] = -1082130432;
  return result;
}
