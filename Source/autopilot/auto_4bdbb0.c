
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

__int16 __thiscall auto_4bdbb0(int self)
{
  __int16 result; // ax

  result = *(_WORD *)(self + 2068);
  if ( result != -1 )
    return *(_WORD *)(*(_DWORD *)(self + 2084) + 102 * result + 100);
  return result;
}
