
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5d1f00(_DWORD *self, char a2)
{
  int v2; // ecx
  int result; // eax

  v2 = self[5];
  for ( result = 0; v2; v2 = *(_DWORD *)(v2 + 36) )
  {
    if ( *(_BYTE *)(v2 + 2) == a2 )
      result = *(_DWORD *)(v2 + 24);
  }
  return result;
}
