
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5eb0f0(_DWORD *self, int a2)
{
  int v2; // ecx
  int result; // eax

  if ( a2 == -1 )
    return 0;
  v2 = self[118];
  result = *(_DWORD *)(v2 + 188);
  if ( result == v2 )
    return 0;
  while ( *(_DWORD *)(result + 196) != a2 )
  {
    result = *(_DWORD *)(result + 188);
    if ( result == v2 )
      return 0;
  }
  return result;
}
