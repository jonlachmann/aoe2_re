
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_580af0(_DWORD *self, int a2)
{
  int v2; // eax
  _DWORD *i; // ecx

  v2 = 0;
  for ( i = self + 345; *i != a2; i += 6 )
  {
    if ( ++v2 >= 50 )
      return 0;
  }
  return 1;
}
