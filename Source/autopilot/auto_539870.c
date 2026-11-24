
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_539870(_DWORD *self, char a2)
{
  int result; // eax

  result = self[1];
  if ( !result )
    return 0;
  while ( *(_BYTE *)result != a2 )
  {
    result = *(_DWORD *)(result + 24);
    if ( !result )
      return 0;
  }
  return result;
}
