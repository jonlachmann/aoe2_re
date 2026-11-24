
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_4359b0(_DWORD *self, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  *a2 = *(_DWORD *)(self[2] + 308);
  result = a3;
  *a3 = *(_DWORD *)(self[2] + 352);
  return result;
}
