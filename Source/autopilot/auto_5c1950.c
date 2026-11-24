
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c1950(_DWORD *self, unsigned int a2)
{
  if ( a2 >= 0x10 )
    return 0;
  else
    return self[6 * a2 + 1661];
}
