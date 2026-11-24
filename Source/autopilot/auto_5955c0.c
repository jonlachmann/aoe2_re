
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_5955c0(int a1)
{
  int result; // eax

  result = -1;
  if ( !a1 )
    return -1;
  if ( *(_BYTE *)(a1 + 32) )
    return **(_DWORD **)(a1 + 36);
  return result;
}
