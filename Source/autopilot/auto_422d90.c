
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_422d90(_DWORD *self, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 > 0 && a2 <= 9 )
    self[a2 + 11] = a3;
  return result;
}
