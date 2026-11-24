
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4175b0(int self)
{
  int result; // eax

  result = 1;
  if ( *(_BYTE *)(self + 376) != 1 || *(_DWORD *)(self + 160) || *(_DWORD *)(self + 48) != -1 )
    return 0;
  return result;
}
