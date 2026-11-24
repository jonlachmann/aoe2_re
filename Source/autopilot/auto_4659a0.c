
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4659a0(int *self, int a2, int a3)
{
  int v3; // eax

  if ( a2 < 0 )
    return 0;
  if ( *self <= a2 )
    return 0;
  v3 = self[2];
  if ( !v3 )
    return 0;
  *(_DWORD *)(v3 + 4 * a2) = a3;
  return 1;
}
