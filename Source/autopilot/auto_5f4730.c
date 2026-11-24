
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_5f4730(_DWORD *a1)
{
  int v1; // eax

  v1 = a1[7];
  if ( *a1 == 1 )
    return v1 != 3 ? 32 : 17;
  else
    return v1 != 3 ? 17 : 9;
}
