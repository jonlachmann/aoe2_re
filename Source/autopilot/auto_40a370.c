
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_40a370(_DWORD *self, int a2)
{
  if ( a2 < 1 || a2 > 2 )
    return -1;
  else
    return self[a2 + 36];
}
