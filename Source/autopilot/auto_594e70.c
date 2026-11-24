
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_594e70(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    *(_DWORD *)(a1 + 8) = 1;
    return 1;
  }
  return result;
}
