
typedef unsigned int _DWORD;
typedef unsigned short _WORD;
typedef unsigned char _BYTE;
typedef unsigned long long _QWORD;
typedef short __int16;
typedef long long __int64;
typedef signed char _BYTE_SIGNED;

float *__thiscall auto_52c430(float *self, float *a2)
{
  float *result; // eax
  float v3; // [esp+4h] [ebp-8h]
  float v4; // [esp+8h] [ebp-4h]

  result = a2;
  v3 = self[16];
  v4 = self[15];
  *a2 = self[14];
  a2[1] = v3;
  a2[2] = v4;
  return result;
}
