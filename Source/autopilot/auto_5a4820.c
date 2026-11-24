
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5a4820(_BYTE *self, __int16 a2, char a3)
{
  int result; // eax

  result = a2;
  self[a2 + 5848] = a3;
  return result;
}
