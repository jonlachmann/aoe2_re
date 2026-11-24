
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_5bec10(_DWORD *self, _DWORD *a2, _DWORD *a3)
{
  char result; // al

  if ( !*(_BYTE *)(*(_DWORD *)(*self + 4 * self[1]) + 4) )
    return 0;
  *a2 = self[26];
  result = 1;
  *a3 = self[7];
  return result;
}
