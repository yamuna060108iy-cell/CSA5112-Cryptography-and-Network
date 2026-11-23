#include <stdio.h>

long long power(int a, int b, int q) {
    long long r = 1;

    while(b > 0) {
        r = (r * a) % q;
        b--;
    }

    return r;
}

int main() {
    int q = 23, a = 5;
    int xa = 6, xb = 15;
    long long A, B, KA, KB;

    A = power(xa, a, q);
    B = power(xb, a, q);

    KA = power(B, xa, q);
    KB = power(A, xb, q);

    printf("Alice Public Value: %lld\n", A);
    printf("Bob Public Value: %lld\n", B);

    printf("Alice Shared Key: %lld\n", KA);
    printf("Bob Shared Key: %lld\n", KB);

    return 0;
}
