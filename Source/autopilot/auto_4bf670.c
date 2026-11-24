
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_4bf670(_DWORD *self, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax

  if ( a2 )
    *a2 = self[10];
  if ( a3 )
    *a3 = self[11];
  if ( a4 )
    *a4 = self[12];
  result = a5;
  if ( a5 )
    *a5 = self[13];
  return result;
}
