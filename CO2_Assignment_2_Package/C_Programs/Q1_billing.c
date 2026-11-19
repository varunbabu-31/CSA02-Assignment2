#include <stdio.h>

/* Illustrative assumptions because the assignment does not supply
   the original buggy expression or the three billing data sets. */
double bill_total(double price, int quantity) {
    return price * quantity;
}

double net_bill(double total, int senior, double gst_rate) {
    double discount_rate = senior ? 0.10 : 0.0;
    double discount = total * discount_rate;
    double taxable = total - discount;
    double gst = taxable * gst_rate;
    return taxable + gst;
}

int main(void) {
    struct Scenario { double price; int quantity; int senior; double gst; };
    struct Scenario s[] = {
        {100.0, 2, 1, 0.05},
        {250.0, 3, 0, 0.05},
        {80.0, 5, 1, 0.12}
    };
    for (int i = 0; i < 3; ++i) {
        double total = bill_total(s[i].price, s[i].quantity);
        double net = net_bill(total, s[i].senior, s[i].gst);
        printf("Scenario %d: total = Rs. %.2f, net = Rs. %.2f\n",
               i + 1, total, net);
    }
    return 0;
}
