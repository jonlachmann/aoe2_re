
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

unsigned int __thiscall auto_562f00(_DWORD *self, unsigned int a2, int a3)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 < 0x28 )
    self[a2 + 66] = a3;
  return result;
}
