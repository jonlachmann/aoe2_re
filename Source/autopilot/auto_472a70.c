
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_472a70(_DWORD *self)
{
  int result; // eax

  for ( result = 0; result < self[52]; *(_DWORD *)(self[232] + 4 * result - 4) = 2139095039 )
    ++result;
  return result;
}
