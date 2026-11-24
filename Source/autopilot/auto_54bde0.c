
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_54bde0(_DWORD *self)
{
  int v1; // edx
  int result; // eax

  v1 = self[2];
  if ( *(float *)(v1 + 68) <= 0.0 )
    return *(_DWORD *)(*(_DWORD *)(v1 + 8) + 24);
  result = *(_DWORD *)(self[12] + 64);
  if ( !result )
    return *(_DWORD *)(*(_DWORD *)(v1 + 8) + 24);
  return result;
}
