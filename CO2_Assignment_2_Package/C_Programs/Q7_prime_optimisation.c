#include <stdio.h>

unsigned long long original_checks, optimised_checks;

int prime_original(unsigned long n) {
    original_checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i < n; ++i) {
        ++original_checks;
        if (n % i == 0) return 0;
    }
    return 1;
}

int prime_optimised(unsigned long n) {
    optimised_checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; ++i) {
        ++optimised_checks;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    unsigned long values[] = {97, 7919, 1000003};
    for (int k = 0; k < 3; ++k) {
        unsigned long n = values[k];
        int a = prime_original(n);
        int b = prime_optimised(n);
        double improvement =
            original_checks == 0 ? 0.0 :
            (1.0 - (double)optimised_checks / original_checks) * 100.0;

        printf("n=%lu result=%s original=%llu optimised=%llu reduction=%.2f%%\n",
               n, (a && b) ? "prime" : "not prime",
               original_checks, optimised_checks, improvement);
    }
    return 0;
}
