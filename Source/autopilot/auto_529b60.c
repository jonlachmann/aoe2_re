
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_529b60(_DWORD *self, __int16 a2)
{
  int v2; // eax

  if ( a2 < 0 )
    return 0;
  v2 = *(_DWORD *)(self[3] + 140);
  if ( a2 >= *(__int16 *)(v2 + 64) )
    return 0;
  else
    return *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * a2);
}
