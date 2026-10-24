#include <stdio.h>

int main() {
    int P[4] = {10, 20, 30, 40};
    int C[4], D[4], E[4];
    int i;

    /* Toy reversible block transform: NOT real encryption */
    for (i = 0; i < 4; i++)
        C[i] = P[i] ^ 15;

    printf("ECB original plaintext: ");
    for (i = 0; i < 4; i++)
        printf("%d ", C[i] ^ 15);

    /* Introduce an error in ciphertext block 1 */
    C[0] ^= 1;

    printf("\nECB after error: ");
    for (i = 0; i < 4; i++)
        printf("%d ", C[i] ^ 15);

    /* CBC error effect: toy illustration */
    for (i = 0; i < 4; i++)
        E[i] = P[i] ^ (i ? E[i-1] : 7);

    E[0] ^= 1;

    D[0] = E[0] ^ 7;
    for (i = 1; i < 4; i++)
        D[i] = E[i] ^ E[i-1];

    printf("\nCBC after error: ");
    for (i = 0; i < 4; i++)
        printf("%d ", D[i]);

    printf("\n");
    return 0;
}
