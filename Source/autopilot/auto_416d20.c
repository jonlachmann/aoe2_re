
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

int __thiscall auto_416d20(_DWORD *self)
{
  int result; // eax

  result = self[13];
  if ( result != -1 )
  {
    self[22] = result;
    self[23] = self[14];
    result = -1082130432;
    self[13] = -1;
    self[14] = -1;
    self[15] = -1082130432;
    self[16] = -1082130432;
    self[17] = -1082130432;
  }
  return result;
}
