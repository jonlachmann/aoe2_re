
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __cdecl auto_446050(int a1, unsigned int *a2, int *a3, _DWORD *a4)
{
  int result; // eax

  *a2 = (*(_DWORD *)(a1 + 4) + 3) & 0xFFFFFFFC;
  result = *(_DWORD *)(a1 + 8);
  *a3 = result;
  if ( result >= 0 )
  {
    *a4 = -1;
  }
  else
  {
    *a3 = -result;
    result = (int)a4;
    *a4 = 1;
  }
  return result;
}
