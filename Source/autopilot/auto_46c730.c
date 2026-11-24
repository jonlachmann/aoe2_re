
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_46c730(_DWORD *self, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 != -1 )
  {
    result = 48 * a2;
    *(_DWORD *)(self[55] + 48 * a2 + 28) = 0;
  }
  return result;
}
