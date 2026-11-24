
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char *__thiscall auto_411940(_WORD *self)
{
  char *result; // eax
  int v2; // ecx

  self[4] = -1;
  *(_DWORD *)self = 0;
  *((_DWORD *)self + 1) = 0;
  self[5] = -1;
  *((_BYTE *)self + 12) = 0;
  *((_BYTE *)self + 13) = 0;
  result = (char *)(self + 10);
  v2 = 16;
  do
  {
    *((_DWORD *)result - 1) = 0;
    *(_WORD *)result = -1;
    *((_DWORD *)result + 1) = 0;
    *((_DWORD *)result + 2) = 0;
    *((_DWORD *)result + 3) = 0;
    *((_DWORD *)result + 4) = 0;
    result += 24;
    --v2;
  }
  while ( v2 );
  return result;
}
