
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_BYTE *__thiscall auto_410530(_BYTE **self)
{
  _BYTE *result; // eax

  *self[255] = 0;
  *((_DWORD *)self[255] + 65) = -1;
  result = self[255];
  result[264] = 0;
  *((_DWORD *)self[255] + 98) = 25;
  return result;
}
