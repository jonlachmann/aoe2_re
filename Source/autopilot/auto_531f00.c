
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_531f00(_DWORD *self, unsigned int a2)
{
  int v2; // eax

  if ( a2 < 4 && (v2 = self[a2 + 114]) != 0 )
    return *(_DWORD *)(v2 + 4);
  else
    return -1;
}
