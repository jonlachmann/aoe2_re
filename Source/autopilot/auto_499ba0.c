
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __cdecl auto_499ba0(_BYTE *a1)
{
  _BYTE *v1; // ecx
  char result; // al

  v1 = a1;
  for ( result = *a1; result; ++v1 )
  {
    if ( result == 95 )
      *v1 = 32;
    result = v1[1];
  }
  return result;
}
