
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_4bf6e0(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 16);
  if ( result )
  {
    *(_DWORD *)(result + 20) = 0;
    *(_DWORD *)(a1 + 16) = 0;
  }
  return result;
}
