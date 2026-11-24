
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_5f3290(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = a1;
  v3 = a2 + *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 28) = v3;
  if ( v3 > 32 )
  {
    *(_DWORD *)(a1 + 28) = v3 - 32;
    *(_DWORD *)(a1 + 8) -= 4;
  }
  return result;
}
