
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5c06b0(_DWORD *self, int a2)
{
  if ( a2 >= self[6] || a2 < 0 )
    return 0;
  else
    return *(_DWORD *)(self[4] + 4 * a2);
}
