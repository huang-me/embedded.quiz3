#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool powerof4(int num)
{
    return num > 0 && (num & (num - 1)) == 0 && __builtin_clz(num) & 0x1;
}

int main()
{
    printf("%d\n", powerof4(16));
    return 0;
}
