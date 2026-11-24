
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

double __thiscall auto_4919a0(_DWORD *self, int a2)
{
  int v2; // edx

  v2 = self[4];
  if ( v2 && *(float *)(v2 + 100) > 0.0 )
    return *(float *)(self[2] + 196) * *(float *)(v2 + 100);
  else
    return *(float *)(self[2] + 196);
}
