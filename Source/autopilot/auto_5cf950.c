
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5cf950(_BYTE *self, int a2, int a3)
{
  if ( a2 < 1 || a2 >= 9 || a3 < 1 || a3 > 5 )
    return 0;
  self[a2 + 650] = a3;
  return 1;
}
