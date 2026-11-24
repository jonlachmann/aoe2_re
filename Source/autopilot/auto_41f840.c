
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41f840(_DWORD *self)
{
  int v1; // eax
  __int16 v2; // dx
  __int16 v3; // cx

  v1 = self[263];
  if ( v1 && (v2 = *(_WORD *)(v1 + 72), v2 >= 1) && (v3 = *(_WORD *)(v1 + 148), v3 < v2) && v3 >= 0 )
    return *(_DWORD *)(*(_DWORD *)(v1 + 76) + 4 * v3);
  else
    return 0;
}
