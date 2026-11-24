
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_54bdb0(_DWORD *self)
{
  int result; // eax

  if ( *(float *)(self[2] + 68) <= 0.0 )
    return *(_DWORD *)(self[12] + 52);
  result = *(_DWORD *)(self[12] + 64);
  if ( !result )
    return *(_DWORD *)(self[12] + 52);
  return result;
}
