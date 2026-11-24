
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5ea4d0(int self)
{
  int result; // eax

  if ( *(_BYTE *)(self + 140) )
  {
    result = *(_DWORD *)(self + 136);
    if ( result < *(_DWORD *)(self + 132) )
      *(_DWORD *)(self + 132) = result - 1;
  }
  else
  {
    result = *(_DWORD *)(self + 132);
    *(_DWORD *)(self + 132) = result - 1;
  }
  return result;
}
