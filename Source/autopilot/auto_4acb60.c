
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4acb60(_DWORD *self)
{
  int v1; // eax

  v1 = self[86];
  if ( v1 )
    return *(_DWORD *)(v1 + 4);
  else
    return -1;
}
