
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_5beb70(_DWORD *self, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  char result; // al

  if ( !*(_BYTE *)(*(_DWORD *)(*self + 4 * self[1]) + 16) )
    return 0;
  *a2 = self[19];
  *a3 = self[20];
  *a4 = self[21];
  result = 1;
  *a5 = self[22];
  return result;
}
