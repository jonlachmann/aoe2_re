
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_437740(_DWORD *self, unsigned int a2)
{
  int result; // eax

  result = a2;
  if ( a2 < self[2] )
  {
    result = 9 * a2;
    *(_DWORD *)(self[69] + 36 * a2 + 28) = 1;
  }
  return result;
}
