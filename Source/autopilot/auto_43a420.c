
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_43a420(int self)
{
  int result; // eax

  *(_WORD *)(self + 40) = 0;
  *(_DWORD *)(self + 44) = 0;
  result = self + 208;
  *(_DWORD *)(self + 208) = 0;
  *(_DWORD *)(self + 212) = 0;
  *(_BYTE *)(self + 216) = 0;
  return result;
}
