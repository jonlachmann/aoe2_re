
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_524320(_DWORD *self)
{
  int v1; // ecx
  int result; // eax
  int v3; // edx
  _WORD *v4; // ecx

  v1 = self[602];
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(v1 + 4) != 70 )
    return 0;
  v3 = *(__int16 *)(v1 + 290);
  result = 0;
  if ( v3 > 0 )
  {
    v4 = *(_WORD **)(v1 + 292);
    do
    {
      if ( *v4 == 3 )
        result = (__int16)v4[1];
      v4 += 2;
      --v3;
    }
    while ( v3 );
  }
  return result;
}
