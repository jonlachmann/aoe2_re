
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_5efe20(int a1, int a2)
{
  int result; // eax

  *(_DWORD *)(a2 + 12) = 0;
  result = *(_DWORD *)(*(_DWORD *)(a1 + 56) + 20120);
  *(_DWORD *)(a2 + 16) = result;
  if ( result )
    *(_DWORD *)(result + 12) = a2;
  *(_DWORD *)(*(_DWORD *)(a1 + 56) + 20120) = a2;
  return result;
}
