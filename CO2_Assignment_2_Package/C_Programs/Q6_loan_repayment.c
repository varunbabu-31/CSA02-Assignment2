#include <stdio.h>

int main(void) {
    double balance = 10000.0;
    const double rate = 0.02;
    const double regular_payment = 2000.0;
    double total_interest = 0.0;
    int month = 0;

    printf("Month  Opening     Interest   Payment    Closing\n");
    while (balance > 0.005 && month < 360) {
        ++month;
        double opening = balance;
        double interest = opening * rate;
        double due = opening + interest;

        if (regular_payment <= interest) {
            printf("Repayment does not exceed monthly interest; loan will not shrink.\n");
            break;
        }

        double payment = regular_payment;
        if (payment > due) payment = due;
        balance = due - payment;
        if (balance < 0.005) balance = 0.0;
        total_interest += interest;

        printf("%5d  %9.2f  %9.2f  %9.2f  %9.2f\n",
               month, opening, interest, payment, balance);
    }

    if (balance == 0.0)
        printf("Settled in %d months. Total interest = Rs. %.2f\n",
               month, total_interest);
    else if (month >= 360)
        printf("Safety limit reached. Remaining balance = Rs. %.2f\n", balance);

    return 0;
}
