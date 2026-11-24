
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_499e40(_DWORD *self, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)self[1];
  if ( !v2 )
    return 0;
  while ( !*v2 || *(_DWORD *)(*v2 + 4) != a2 )
  {
    v2 = (_DWORD *)v2[1];
    if ( !v2 )
      return 0;
  }
  return *v2;
}
