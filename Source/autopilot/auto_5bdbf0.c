
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_5bdbf0(_DWORD *self, int a2, int a3)
{
  if ( !*(_BYTE *)(*(_DWORD *)(*self + 4 * self[1]) + a2) )
    return 0;
  self[a2 + 3] = a3;
  return 1;
}
