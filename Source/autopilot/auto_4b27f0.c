
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4b27f0(_DWORD *self, int a2)
{
  int result; // eax

  result = self[64];
  if ( result )
    *(_DWORD *)(result + 372) = a2;
  return result;
}
