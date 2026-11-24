
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_45ea60(_DWORD *self)
{
  _DWORD *result; // eax

  result = (_DWORD *)self[5];
  for ( self[19] = 0; result; result = (_DWORD *)result[2] )
    *(_DWORD *)(*result + 244) = 0;
  return result;
}
