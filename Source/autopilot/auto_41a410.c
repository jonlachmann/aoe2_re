
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_41a410(_BYTE *self, int a2)
{
  char result; // al

  result = self[79];
  if ( result )
    self[79] = --result;
  return result;
}
