
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_460620(_DWORD *self)
{
  int v1; // eax
  int v2; // edx
  int result; // eax

  v1 = self[20];
  v2 = self[3];
  self[8] = v1;
  *(_DWORD *)(v2 + 4) = v1;
  result = self[42];
  self[58] = (result & 0x800) == 0;
  return result;
}
