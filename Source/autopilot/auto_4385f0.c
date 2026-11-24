
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4385f0(_DWORD *self, int a2, int a3, int a4)
{
  int result; // eax

  result = self[80];
  if ( !result )
  {
    self[72] = a2;
    result = a4;
    self[76] = a3;
    self[80] = a4;
  }
  return result;
}
