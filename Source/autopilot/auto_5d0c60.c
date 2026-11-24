
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_5d0c60(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 40);
  if ( result )
  {
    if ( *(_BYTE *)(result + 72) == 7 )
    {
      *(_BYTE *)(a1 + 46) = 2;
      *(_DWORD *)(a1 + 40) = 0;
    }
  }
  return result;
}
