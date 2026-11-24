
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4bd400(_DWORD *self, int a2)
{
  int v2; // ecx
  int result; // eax

  v2 = self[62];
  result = 0;
  if ( !v2 )
    return -1;
  while ( *(_DWORD *)(v2 + 8) != a2 )
  {
    v2 = *(_DWORD *)(v2 + 36);
    ++result;
    if ( !v2 )
      return -1;
  }
  return result;
}
