
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

char __stdcall auto_59abf0(char a1)
{
  char result; // al

  result = a1;
  if ( a1 != 1 )
  {
    if ( a1 == 22 )
      return 1;
    else
      return a1 == 4 || a1 == 23 || a1 == 26;
  }
  return result;
}
