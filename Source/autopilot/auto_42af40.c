
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_42af40(_DWORD *self)
{
  int result; // eax
  _DWORD *v2; // ecx
  int v3; // edx

  result = 0;
  v2 = (_DWORD *)(self[1910] + 4);
  v3 = 502;
  do
  {
    if ( *v2 )
      ++result;
    v2 += 14;
    --v3;
  }
  while ( v3 );
  return result;
}
