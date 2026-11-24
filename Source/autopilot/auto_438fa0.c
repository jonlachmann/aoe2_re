
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __stdcall auto_438fa0(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  *a1 = *a2;
  a1[1] = a2[1];
  a1[2] = a2[2];
  result = a2[3];
  a1[3] = result;
  return result;
}
