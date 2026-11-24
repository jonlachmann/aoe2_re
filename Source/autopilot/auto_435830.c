
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_435830(int self)
{
  int result; // eax

  result = *(_DWORD *)(self + 8);
  *(float *)(self + 360) = *(float *)(result + 320);
  return result;
}
