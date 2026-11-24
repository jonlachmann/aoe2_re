
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_433500(_DWORD *self, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( self[a2 + 4527] == 5 )
    self[a2 + 4527] = a3;
  return result;
}
