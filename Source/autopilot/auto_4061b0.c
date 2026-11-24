
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4061b0(_DWORD *self)
{
  int v1; // eax

  v1 = self[2];
  if ( v1 )
    return *(_DWORD *)(*(_DWORD *)v1 + 48);
  else
    return 0;
}
