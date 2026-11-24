
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4118c0(_DWORD *self, int a2)
{
  if ( a2 < 0 || a2 >= self[27] )
    return -1;
  else
    return self[a2 + 3];
}
