
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_433e70(int self, _DWORD *a2, _DWORD *a3)
{
  if ( !*(_BYTE *)(self + 24) )
    return 0;
  *a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(self + 20) + 12) + 8);
  *a3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(self + 20) + 12) + 12);
  return 1;
}
