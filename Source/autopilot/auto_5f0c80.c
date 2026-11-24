
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_5f0c80(int a1, unsigned int a2)
{
  unsigned int *v3; // eax

  if ( *(_DWORD *)(a1 + 8) )
    return -102;
  v3 = *(unsigned int **)(a1 + 12);
  if ( a2 >= v3[1] )
    return -101;
  *v3 = a2;
  return 0;
}
