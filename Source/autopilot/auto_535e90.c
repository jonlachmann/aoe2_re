
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

bool __thiscall auto_535e90(_DWORD *self, int a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = self[2];
  v3 = *(__int16 *)(v2 + 22);
  return v3 != 9 && v3 != 10 && v3 != 58 || a2 == 4 || *(_BYTE *)(v2 + 4) == 60;
}
