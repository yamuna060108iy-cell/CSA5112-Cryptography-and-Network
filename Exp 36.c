
#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char pt[100];
    int a, b, i, p;

    printf("Enter plaintext: ");
    scanf("%99s", pt);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if(gcd(a, 26) != 1) {
        printf("Invalid key. Encryption is not one-to-one.");
        return 0;
    }

    for(i = 0; pt[i] != '\0'; i++) {
        p = pt[i] - 'A';
        pt[i] = ((a * p + b) % 26) + 'A';
    }

    printf("Ciphertext: %s\n", pt);

    return 0;
}
