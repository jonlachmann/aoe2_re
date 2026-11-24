
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

bool __thiscall auto_4e8230(_DWORD *self, int a2)
{
  int v2; // eax

  v2 = self[1152];
  return *(_BYTE *)(v2 + 650) && *(float *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 76) + 4 * a2) + 168) + 28) > 0.0;
}
