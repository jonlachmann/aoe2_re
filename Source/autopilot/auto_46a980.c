
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_46a980(_DWORD *self, _DWORD *a2)
{
  _DWORD *v2; // ecx
  int result; // eax

  v2 = self + 25;
  *v2 = *a2;
  v2[1] = a2[1];
  result = a2[2];
  v2[2] = result;
  return result;
}
