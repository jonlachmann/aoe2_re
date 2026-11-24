
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_42db70(int self, unsigned int a2)
{
  if ( a2 > *(unsigned __int16 *)(self + 4824) )
    return 0;
  if ( a2 == *(_DWORD *)(self + 4320) )
    return self + 4344;
  return (a2 << 7) + *(_DWORD *)(self + 4808);
}
