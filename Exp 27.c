#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    int e, n, i, j;
    long long c, result;

    printf("Enter message: ");
    scanf("%99s", msg);

    printf("Enter public exponent: ");
    scanf("%d", &e);

    printf("Enter modulus: ");
    scanf("%d", &n);

    printf("\nEncrypted values:\n");

    for(i = 0; msg[i] != '\0'; i++) {
        int p = msg[i] - 'A';
        result = 1;

        for(j = 0; j < e; j++)
            result = (result * p) % n;

        c = result;
        printf("%lld ", c);
    }

    return 0;
}
