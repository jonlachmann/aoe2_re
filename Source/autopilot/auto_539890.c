
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __thiscall auto_539890(_DWORD *self, int a2, _DWORD *a3)
{
  int v3; // eax
  int v4; // ecx
  char result; // al

  v3 = self[1];
  v4 = 1;
  if ( v3 )
  {
    while ( v4 != a2 )
    {
      v3 = *(_DWORD *)(v3 + 24);
      ++v4;
      if ( !v3 )
        goto LABEL_4;
    }
    *a3 = v3;
    return 1;
  }
  else
  {
LABEL_4:
    result = 0;
    *a3 = 0;
  }
  return result;
}
