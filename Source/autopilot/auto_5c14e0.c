
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c14e0(_DWORD *self, unsigned int a2, unsigned int a3)
{
  if ( a2 >= 0x10 || a3 >= 0x10 )
    return -1;
  else
    return self[16 * a2 + 4643 + a3];
}
