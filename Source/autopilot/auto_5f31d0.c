
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__cdecl auto_5f31d0(_DWORD *a1)
{
  _DWORD *result; // eax
  int v2; // ecx
  int v3; // ecx

  result = a1;
  v2 = a1[1];
  a1[7] = 32;
  a1[2] = v2;
  v3 = a1[3];
  a1[4] = v3;
  a1[5] = v3;
  a1[6] = 0;
  a1[10] = 0;
  a1[9] = 0;
  return result;
}
