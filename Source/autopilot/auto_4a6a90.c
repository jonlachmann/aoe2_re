
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4a6a90(_DWORD *self, int a2)
{
  int i; // eax
  int result; // eax

  for ( i = self[1]; i; i = *(_DWORD *)(i + 4) )
    ;
  result = self[11];
  if ( a2 == 1 )
    self[11] = result - 1;
  return result;
}
