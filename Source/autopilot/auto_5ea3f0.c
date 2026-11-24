
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_5ea3f0(_DWORD *self)
{
  int v1; // eax

  v1 = self[13];
  if ( v1 )
    return *(_BYTE *)(v1 + 36558);
  else
    return 0;
}
