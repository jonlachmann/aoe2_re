
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_583670(_DWORD *self, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx

  v2 = (_DWORD *)self[661];
  v3 = self + 647;
  if ( v2 != v3 )
  {
    while ( v2 )
    {
      if ( v2[18] == 108 && v2[63] == a2 )
        return 1;
      v2 = (_DWORD *)v2[14];
      if ( v2 == v3 )
        return 0;
    }
  }
  return 0;
}
