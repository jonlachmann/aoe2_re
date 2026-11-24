
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5219b0(_DWORD *self, int a2)
{
  int v2; // eax

  v2 = self[32];
  if ( !v2 )
    return 0;
  while ( **(_DWORD **)(v2 + 8) != a2 )
  {
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v2 )
      return 0;
  }
  return *(_DWORD *)(v2 + 8);
}
