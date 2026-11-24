
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_5eacb0(_DWORD *self, int a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx

  if ( a2 == -1 )
    return 0;
  result = (_DWORD *)self[103];
  v3 = self + 103;
  if ( result == v3 )
    return 0;
  while ( result[2] != a2 )
  {
    result = (_DWORD *)*result;
    if ( result == v3 )
      return 0;
  }
  return result;
}
