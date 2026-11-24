
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4886c0(_DWORD *self)
{
  int result; // eax
  int v2; // eax

  result = self[42];
  if ( result )
  {
    v2 = *(_DWORD *)(result + 28);
    return v2 == 1 || v2 == 2;
  }
  return result;
}
