#include <stdio.h>

int main() {
    int hash = 25;
    int private_key = 7;
    int k1 = 3, k2 = 5;
    int s1, s2;

    s1 = (hash + k1 * private_key) % 100;
    s2 = (hash + k2 * private_key) % 100;

    printf("Message Hash: %d\n", hash);

    printf("Signature 1: %d\n", s1);
    printf("Signature 2: %d\n", s2);

    if(s1 != s2)
        printf("Signatures are different.\n");
    else
        printf("Signatures are same.\n");

    return 0;
}
