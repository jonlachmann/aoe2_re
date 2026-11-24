
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c13a0(int self, int a2)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(self + 21028) = a2;
  if ( a2 != 4 )
    *(_BYTE *)(self + 12) = 1;
  return result;
}
