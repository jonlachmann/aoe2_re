
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__cdecl auto_5f87b0(_DWORD *a1)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1[7] == 1 )
    a1[12] = 4 * a1[8] + 4;
  else
    a1[12] = 0;
  return result;
}
