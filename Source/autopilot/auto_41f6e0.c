
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_41f6e0(int self, int a2)
{
  int v2; // edx

  v2 = *(_DWORD *)(self + 140);
  if ( v2 && a2 >= 0 && a2 < *(__int16 *)(self + 136) )
    return *(_DWORD *)(v2 + 4 * a2);
  else
    return 0;
}
