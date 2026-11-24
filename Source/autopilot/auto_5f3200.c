
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__cdecl auto_5f3200(_DWORD *a1)
{
  _DWORD *result; // eax
  int v2; // ecx

  result = a1;
  v2 = a1[3];
  a1[6] = 0;
  a1[4] = v2;
  a1[5] = v2;
  return result;
}
