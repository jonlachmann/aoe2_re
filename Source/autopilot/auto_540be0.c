
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_540be0(_DWORD *self)
{
  int v1; // eax
  int v2; // edx
  int v3; // ecx

  v1 = self[2];
  v2 = *(_DWORD *)(v1 + 8);
  v3 = *(_DWORD *)(v2 + 428);
  if ( v3 < 0 )
    return *(_DWORD *)(v2 + 200);
  else
    return *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 12) + 140) + 68) + 4 * v3);
}
