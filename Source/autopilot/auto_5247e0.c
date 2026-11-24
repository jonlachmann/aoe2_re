
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_5247e0(int a1, int a2)
{
  int result; // eax
  char v3; // cl

  result = a1;
  if ( a1 )
  {
    v3 = *(_BYTE *)(a1 + 64);
    if ( a2 )
      *(_BYTE *)(a1 + 64) = v3 & 0xEF;
    else
      *(_BYTE *)(a1 + 64) = v3 | 0x10;
  }
  return result;
}
