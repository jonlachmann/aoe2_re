
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4388f0(_DWORD *self, unsigned int a2)
{
  if ( a2 && a2 <= 9 )
    return self[a2 + 81];
  else
    return 0;
}
