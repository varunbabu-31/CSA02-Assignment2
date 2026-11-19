#include <stdio.h>

int verification_calls = 0;

int verify_certificate(void) {
    ++verification_calls;
    return 1; /* Simulated successful server response */
}

int eligible_short_circuit(int age, int category) {
    return (age >= 60 && category == 1 && verify_certificate());
}

int eligible_bitwise(int age, int category) {
    /* Bitwise &: all operands are evaluated; use only with 0/1 values. */
    return (age >= 60) & (category == 1) & verify_certificate();
}

int main(void) {
    int ages[] = {25, 65, 70, 45, 80};
    int categories[] = {1, 1, 2, 1, 1};
    int n = 5;

    verification_calls = 0;
    for (int i = 0; i < n; ++i)
        (void)eligible_short_circuit(ages[i], categories[i]);
    printf("Short-circuit verification calls: %d of %d\n",
           verification_calls, n);

    verification_calls = 0;
    for (int i = 0; i < n; ++i)
        (void)eligible_bitwise(ages[i], categories[i]);
    printf("Bitwise verification calls: %d of %d\n",
           verification_calls, n);

    return 0;
}
