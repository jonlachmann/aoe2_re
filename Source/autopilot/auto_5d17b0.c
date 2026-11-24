
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5d17b0(_DWORD *self, int a2)
{
  int result; // eax
  int v3; // edx

  result = self[1];
  v3 = 0;
  if ( !result )
    return 0;
  while ( v3 != a2 )
  {
    result = *(_DWORD *)(result + 48);
    ++v3;
    if ( !result )
      return 0;
  }
  return result;
}
