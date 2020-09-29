#include <stdio.h>
#include <stdlib.h>

int numOfSteps(int num) {
    return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
}

int msb(int num)
{
    float f = (float) num;
    return num ? ((*(int *) &f >> 23) - 0x7f) : 0;
}

int setbits(int v)
{
    int out = 0;
    while (v) {
        out++;
        v &= v - 1;
    }
    return out;
}

int steps(int num)
{
    return setbits(num) + msb(num);
}

int main() {
    int num = 83962;
    printf("%d\n", numOfSteps(num));
    printf("my numofsteps: %d\n", steps(num));
    return 0;
}
