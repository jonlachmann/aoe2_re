
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_4a6a30(_DWORD *self)
{
  int v1; // ecx
  int result; // eax

  v1 = self[1];
  if ( !v1 )
    return 0;
  do
  {
    result = v1;
    v1 = *(_DWORD *)(v1 + 4);
  }
  while ( v1 );
  return result;
}
