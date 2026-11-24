
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4a6a10(_DWORD *self)
{
  int v1; // edx
  int result; // eax

  v1 = self[1];
  for ( result = self[4]; v1; v1 = *(_DWORD *)(v1 + 4) )
    result = *(_DWORD *)(v1 + 16);
  return result;
}
