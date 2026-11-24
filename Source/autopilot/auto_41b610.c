
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

bool __thiscall auto_41b610(int self)
{
  int v1; // eax

  v1 = *(_DWORD *)(self + 4);
  if ( !v1 )
    return 0;
  return *(_BYTE *)(self + 36) && (*(_BYTE *)(v1 + 112) & 1) != 0;
}
