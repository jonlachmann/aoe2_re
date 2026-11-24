
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_595540(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 16);
  else
    return -1;
}
