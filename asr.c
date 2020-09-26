#include <stdio.h>
#include <stdlib.h>

int asr_i(signed int, unsigned int);

int main() {
    int signed_int = -5, shift_amount = 1;
    signed_int = asr_i(signed_int, shift_amount);
    return 0;
}

int asr_i(signed int m, unsigned int n)
{
    const int logical = (((int) -1) >> 1) > 0;
    unsigned int fixu = -(logical & (m < 0));
    int fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}
