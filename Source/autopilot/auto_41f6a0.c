
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41f6a0(_DWORD *self, int a2)
{
  int v2; // ecx

  v2 = self[131];
  if ( v2 )
    return v2 + 12 * a2;
  else
    return 0;
}
