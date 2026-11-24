
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_537d70(_DWORD *self)
{
  int v1; // eax

  v1 = self[104];
  if ( v1 < 1 )
    return 0;
  self[104] = v1 - 1;
  return 1;
}
