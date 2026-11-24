
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4937a0(int *self, int a2)
{
  if ( a2 < 0 || a2 >= *self )
    return -1;
  else
    return *(_DWORD *)(self[3] + 4 * a2);
}
