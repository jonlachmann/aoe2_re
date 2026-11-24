
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4bd5b0(_DWORD *self, int a2)
{
  int v2; // eax
  int v3; // edx

  v2 = self[62];
  v3 = 0;
  if ( !v2 )
    return -1;
  while ( v3 != a2 )
  {
    v2 = *(_DWORD *)(v2 + 36);
    ++v3;
    if ( !v2 )
      return -1;
  }
  return *(_DWORD *)(v2 + 8);
}
