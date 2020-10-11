#include <stdint.h>
#include <stdio.h>
#include <time.h>

uint64_t gcd64(uint64_t u, uint64_t v) {
    if (!u || !v) return u | v;
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u /= 2, v /= 2;
    }
    while (!(u & 1))
        u /= 2;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

uint64_t builtin_gcd(uint64_t u, uint64_t v)
{
    if (!(u & v))
        return u | v;
    int ctz_u = __builtin_ctz(u), ctz_v = __builtin_ctz(v);
    int shift = (ctz_u > ctz_v) ? ctz_v : ctz_u;
    u >>= shift;
    v >>= shift;
    u >>= __builtin_ctz(u);
    //    while (!(u & 1))
    //      u /= 2;
    do {
        v >>= __builtin_ctz(v);
        // while (!(v & 1))
        //  v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int main() {
    int x, y, tmp;
    FILE *gcd, *builtin;
    gcd = fopen("gcd.txt", "w+");
    builtin = fopen("builtin_gcd.txt", "w+");
    clock_t start, end;
    for (x = 5000; x < 10000; x++) {
        start = clock();
        for (y = 5000; y < 10000; y++) {
            // printf("%ld\n", gcd64(x, y));
            int tmp = gcd64(x, y);
        }
        end = clock();
        fprintf(gcd, "%f\n", ((double) end - start) / CLOCKS_PER_SEC);
    }

    for (x = 5000; x < 10000; x++) {
        start = clock();
        for (y = 5000; y < 10000; y++) {
            // printf("%ld\n", builtin_gcd(x, y));
            int tmp = builtin_gcd(x, y);
        }
        end = clock();
        fprintf(builtin, "%f\n", ((double) end - start) / CLOCKS_PER_SEC);
    }
}
