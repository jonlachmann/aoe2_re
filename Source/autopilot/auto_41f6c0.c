
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41f6c0(_DWORD *self, int a2)
{
  int result; // eax

  result = self[31];
  if ( result )
    return *(_DWORD *)(result + 4 * a2);
  return result;
}
