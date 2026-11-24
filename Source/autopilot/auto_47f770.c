
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_47f770(_DWORD *self, _DWORD *a2, _DWORD *a3)
{
  int v3; // eax
  char result; // al

  v3 = self[9150];
  if ( !v3 )
    return 0;
  *a2 = *(_DWORD *)(v3 + 4);
  result = 1;
  *a3 = *(_DWORD *)(self[9150] + 8);
  return result;
}
