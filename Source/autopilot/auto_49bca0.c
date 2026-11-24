
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_49bca0(int a1, char a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 80);
  if ( result )
    *(_BYTE *)(result + 6) = a2 | *(_BYTE *)(result + 6) & 0xF;
  return result;
}
