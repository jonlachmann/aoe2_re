
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_472420(int a1)
{
  int result; // eax

  result = a1;
  if ( *(_BYTE *)(a1 + 78) == 80 )
  {
    if ( *(_DWORD *)(a1 + 452) )
      return *(_DWORD *)(a1 + 452);
  }
  return result;
}
