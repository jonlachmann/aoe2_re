
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

double __thiscall auto_48e2d0(_DWORD *self)
{
  int v1; // edx

  v1 = self[4];
  if ( v1 && *(float *)(v1 + 100) > 0.0 )
    return *(float *)(self[2] + 196) * *(float *)(v1 + 100);
  else
    return *(float *)(self[2] + 196);
}
