
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_520750(_BYTE *self)
{
  int result; // eax

  result = 0;
  *(_DWORD *)self = 0;
  self[4] = 0;
  self[5] = 0;
  *((_DWORD *)self + 7) = 0;
  *((_DWORD *)self + 3) = 0;
  *((_DWORD *)self + 4) = 0;
  *((_DWORD *)self + 5) = 0;
  self[24] = 0;
  return result;
}
