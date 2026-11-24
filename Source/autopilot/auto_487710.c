
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_487710(_DWORD *self, int a2)
{
  int result; // eax
  int v3; // ecx

  result = self[1];
  if ( result )
  {
    do
    {
      v3 = result;
      result = *(_DWORD *)(result + 4);
    }
    while ( result );
    result = a2;
    *(_DWORD *)(v3 + 4) = a2;
  }
  else
  {
    self[1] = a2;
  }
  return result;
}
