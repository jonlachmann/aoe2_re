
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_5bb000(_BYTE *self, int a2, int a3)
{
  int result; // eax
  char v4; // dl

  result = a2;
  if ( a2 == 1 )
  {
    v4 = a3;
    if ( a3 == 1 )
    {
      self[4637] = 1;
      return result;
    }
  }
  else
  {
    v4 = a3;
  }
  self[a2 + 4636] = v4;
  return result;
}
