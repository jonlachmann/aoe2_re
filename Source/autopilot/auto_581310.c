
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_581310(_DWORD *self)
{
  _DWORD *v1; // edx
  _DWORD *v2; // ecx
  int result; // eax

  v1 = (_DWORD *)self[661];
  v2 = self + 647;
  for ( result = 0; v1 != v2; v1 = (_DWORD *)v1[14] )
  {
    if ( !v1 )
      break;
    if ( v1[18] == 102 )
      result += v1[60];
  }
  return result;
}
