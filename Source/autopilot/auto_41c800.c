
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char *__thiscall auto_41c800(char *self, int a2, unsigned int a3)
{
  char *result; // eax

  result = &self[32 * a2];
  *((_DWORD *)result + 341) += a3;
  *((_DWORD *)result + 346) = a3;
  if ( a3 > *((_DWORD *)result + 347) )
    *((_DWORD *)result + 347) = a3;
  return result;
}
