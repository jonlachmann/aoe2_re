
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

__int16 __thiscall auto_41b6e0(int self)
{
  __int16 result; // ax

  result = *(_WORD *)(self + 20);
  *(_BYTE *)(self + 34) = 1;
  *(_WORD *)(self + 32) = result;
  *(_WORD *)(self + 20) = 0;
  return result;
}
