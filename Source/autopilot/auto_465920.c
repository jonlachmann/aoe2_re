
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_465920(int *self, int a2)
{
  int v2; // eax

  if ( a2 >= 0 && a2 < *self && (v2 = self[2]) != 0 )
    return *(_DWORD *)(v2 + 4 * a2);
  else
    return -1;
}
