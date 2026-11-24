
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

_DWORD *__thiscall auto_46c750(_DWORD *self, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  if ( a2 != (_DWORD *)-1 )
  {
    result = (_DWORD *)(self[55] + 48 * (_DWORD)a2 + 28);
    ++*result;
  }
  return result;
}
