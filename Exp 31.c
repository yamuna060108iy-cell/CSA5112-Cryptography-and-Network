#include <stdio.h>

int main() {
    unsigned int L, K1, K2;

    printf("Enter initial block value: ");
    scanf("%x", &L);

    K1 = L << 1;

    if(L & 0x80000000)
        K1 ^= 0x87;

    K2 = K1 << 1;

    if(K1 & 0x80000000)
        K2 ^= 0x87;

    printf("Subkey K1: %08X\n", K1);
    printf("Subkey K2: %08X\n", K2);

    printf("\nConstants:\n");
    printf("64-bit block: 1B\n");
    printf("128-bit block: 87\n");

    return 0;
}
