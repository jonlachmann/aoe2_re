
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __fastcall auto_5f9780(int a1, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a2 + 8) = result;
  *(_DWORD *)(a1 + 20) = a2;
  return result;
}
