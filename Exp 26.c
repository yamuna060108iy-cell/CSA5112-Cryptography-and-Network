#include <stdio.h>

int main() {
    int n = 3233;
    int old_e = 17;
    int old_d = 2753;

    int new_e = 7;
    int new_d = 1783;

    printf("RSA Modulus: %d\n", n);

    printf("Old Public Key: %d\n", old_e);
    printf("Old Private Key: %d\n", old_d);

    printf("New Public Key: %d\n", new_e);
    printf("New Private Key: %d\n", new_d);

    printf("\nSame modulus is reused.\n");
    printf("Generating new keys with the same modulus ");
    printf("is NOT safe.\n");

    return 0;
}
