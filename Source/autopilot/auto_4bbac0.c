
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4bbac0(int self, int a2, char a3)
{
  int result; // eax

  result = a2;
  *(_DWORD *)(self + 356) = a2;
  *(_BYTE *)(self + 360) = a3;
  return result;
}
