
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4ac3e0(_DWORD *self, __int16 a2, _DWORD *a3)
{
  if ( a2 < 0 || a2 >= self[41] )
    return 0;
  *a3 = *(_DWORD *)(self[42] + 4 * a2);
  return 1;
}
