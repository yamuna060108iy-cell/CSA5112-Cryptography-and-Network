#include <stdio.h>
#include <math.h>

int main() {
    long double keys = 1;
    int i;

    for (i = 1; i <= 25; i++)
        keys *= i;

    printf("Total possible keys = 25! = %.0Lf\n", keys);
    printf("Approximate power of 2 = 2^%.2Lf\n",
           log2l(keys));

    printf("Effectively unique keys are fewer because "
           "some keys give identical encryption results.\n");

    return 0;
}
