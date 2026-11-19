#include <stdio.h>

int prime_for(unsigned long n) {
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; ++i)
        if (n % i == 0) return 0;
    return 1;
}

int prime_while(unsigned long n) {
    if (n < 2) return 0;
    unsigned long i = 2;
    while (i <= n / i) {
        if (n % i == 0) return 0;
        ++i;
    }
    return 1;
}

int prime_do_while(unsigned long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    unsigned long i = 2;
    do {
        if (n % i == 0) return 0;
        ++i;
    } while (i <= n / i);
    return 1;
}

int main(void) {
    unsigned long values[] = {2, 3, 4, 97, 7919};
    for (int k = 0; k < 5; ++k)
        printf("%lu: for=%d while=%d do-while=%d\n", values[k],
               prime_for(values[k]), prime_while(values[k]),
               prime_do_while(values[k]));
    return 0;
}
