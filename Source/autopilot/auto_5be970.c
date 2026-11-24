
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_5be970(_DWORD *self, int a2, int a3, int a4, int a5)
{
  if ( !*(_BYTE *)(*(_DWORD *)(*self + 4 * self[1]) + 16) )
    return 0;
  self[20] = a3;
  self[19] = a2;
  self[22] = a5;
  self[21] = a4;
  return 1;
}
