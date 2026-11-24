
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_474400(_DWORD *self, __int16 a2)
{
  int v2; // eax

  if ( a2 == -1 )
    return 0;
  v2 = self[62];
  if ( a2 >= *(__int16 *)(v2 + 8) )
    return 0;
  else
    return *(_DWORD *)(*(_DWORD *)(v2 + 4) + 4 * a2);
}
