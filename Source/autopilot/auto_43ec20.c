
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_43ec20(_DWORD *self, int a2)
{
  if ( a2 < 0 || a2 >= self[42] )
    return 0;
  else
    return (int)&self[40 * a2 + 83];
}
