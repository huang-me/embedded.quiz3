#include <stdio.h>
#include <stdlib.h>

#define asr(x, y) _Generic((x), int : asr_i, float : asr_f)(x, y)

int asr_i(signed int, unsigned int);
float asr_f(float, unsigned int);

int main() {
    int signed_int = -5, shift_amount = 2;
    signed_int = asr(signed_int, shift_amount);
    printf("int: %d\n", signed_int);

    float signed_float = -5.0;
    signed_float = asr(signed_float, shift_amount);
    printf("float: %f\n", signed_float);

    return 0;
}

int asr_i(signed int m, unsigned int n)
{
    const int logical = (((int) -1) >> 1) > 0;
    unsigned int fixu = -(logical & (m < 0));
    int fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

float asr_f(float m, unsigned int n)
{
    int tmp = *(int *) &m;
    unsigned int exp = (*(unsigned int *) &tmp) << 1 >> 24;
    exp = (exp - n) << 23;
    tmp &= 0x807fffff;
    tmp |= exp;
    m = *(float *) &tmp;
    return m;
}
