
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5625b0(char *self, int a2)
{
  char *v2; // ecx

  v2 = &self[40 * a2 + 3872 + 4 * a2];
  if ( *(_DWORD *)v2 && *((int *)v2 + 1) >= 1 )
    return 100 * *((_DWORD *)v2 + 6) / *((_DWORD *)v2 + 5);
  else
    return 0;
}
