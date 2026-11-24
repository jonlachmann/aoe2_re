
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_493780(_DWORD *self)
{
  int result; // eax

  for ( result = 0; result < *self; *(_DWORD *)(self[3] + 4 * result - 4) = -1 )
    ++result;
  return result;
}
