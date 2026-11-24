
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_410410(_DWORD *self)
{
  int v1; // eax
  int result; // eax

  v1 = self[937] - 1;
  self[937] = v1;
  result = self[v1 + 938];
  self[120] = result;
  return result;
}
