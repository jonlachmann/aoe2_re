
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_40cfb0(_DWORD *self, int a2, char a3)
{
  int result; // eax

  result = a2;
  if ( a2 > 0 && a2 < *(__int16 *)(*(_DWORD *)(*(_DWORD *)(self[60] + 240) + 140) + 72) )
    *((_BYTE *)self + a2 + 324) = a3;
  return result;
}
