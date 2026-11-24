
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4af0d0(_DWORD *self)
{
  int result; // eax

  result = self[2];
  self[2] = 0;
  return result;
}
