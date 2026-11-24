
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41ac00(_DWORD *self, int a2, char a3)
{
  int result; // eax

  result = self[1];
  if ( result )
  {
    while ( *(_DWORD *)(*(_DWORD *)result + 4) != a2 )
    {
      result = *(_DWORD *)(result + 8);
      if ( !result )
        return result;
    }
    *(_BYTE *)(result + 5) = a3;
  }
  return result;
}
