
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_5f3fb0(_DWORD *a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  *a1 = a2;
  a1[1] = a2 + a3;
  a1[3] = a2;
  a1[2] = a2;
  return result;
}
