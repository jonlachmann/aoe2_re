
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_494da0(float *self, float a2)
{
  int result; // eax
  double v3; // st7

  self[50] = a2;
  result = *(_DWORD *)self;
  v3 = (double)*(int *)(*(_DWORD *)self + 8);
  self[51] = a2;
  self[52] = v3 - a2;
  self[53] = (double)*(int *)(result + 12) - a2;
  return result;
}
