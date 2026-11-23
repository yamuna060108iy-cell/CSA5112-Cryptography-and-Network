#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, m, g;

    printf("Enter RSA modulus n: ");
    scanf("%d", &n);

    printf("Enter plaintext block: ");
    scanf("%d", &m);

    g = gcd(m, n);

    printf("GCD = %d\n", g);

    if(g > 1)
        printf("Common factor found. RSA modulus can be factored.\n");
    else
        printf("No common factor found.\n");

    return 0;
}
