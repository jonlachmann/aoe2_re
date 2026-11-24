
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5a67d0(_DWORD *self, int a2)
{
  int result; // eax
  int v3; // edx

  result = a2;
  if ( a2 )
  {
    result = self[392];
    self[390] = 1;
    self[188] = result;
  }
  else
  {
    v3 = self[384];
    self[390] = 0;
    self[188] = v3;
  }
  return result;
}
