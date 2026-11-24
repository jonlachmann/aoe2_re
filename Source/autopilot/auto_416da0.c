
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_416da0(_DWORD *self, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edx
  int result; // eax

  v6 = self[14];
  self[22] = self[13];
  self[23] = v6;
  self[13] = a2;
  self[14] = a3;
  self[15] = a4;
  result = a6;
  self[16] = a5;
  self[17] = a6;
  return result;
}
