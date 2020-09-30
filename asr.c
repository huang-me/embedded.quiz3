#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define asr(x, y)               \
    _Generic((x), float         \
             : asr_f, int8_t    \
             : asr_i8, int16_t  \
             : asr_i16, int32_t \
             : asr_i32, int64_t \
             : asr_i64)(x, y)

#define asr_int(type)                            \
    const type logical = (((type) -1) >> 1) > 0; \
    u##type fixu = -(logical & (x < 0));         \
    type fix = *(type *) &fixu;                  \
    return (x >> y) | (fix ^ (fix >> y))

int8_t asr_i8(int8_t x, unsigned int y)
{
    asr_int(int8_t);
}

int16_t asr_i16(int16_t x, unsigned int y)
{
    asr_int(int16_t);
}

int32_t asr_i32(int32_t x, unsigned int y)
{
    asr_int(int32_t);
}

int64_t asr_i64(int64_t x, unsigned int y)
{
    asr_int(int64_t);
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

int main() {
    int8_t signed_int8 = -5, shift_amount = 2;
    signed_int8 = asr(signed_int8, shift_amount);
    printf("int8: %d\n", signed_int8);

    int16_t signed16 = -5;
    signed16 = asr(signed16, shift_amount);
    printf("int16: %d\n", signed16);

    int32_t signed32 = -5;
    signed32 = asr(signed32, shift_amount);
    printf("int32: %d\n", signed32);

    int64_t signed64 = -5;
    signed64 = asr(signed64, shift_amount);
    printf("int64: %ld\n", signed64);

    float signed_float = -5.0;
    signed_float = asr(signed_float, shift_amount);
    printf("float: %f\n", signed_float);

    return 0;
}
