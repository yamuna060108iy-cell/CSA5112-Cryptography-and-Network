
#include <stdio.h>

int main() {
    int key[2][2] = {
        {3, 3},
        {2, 5}
    };

    int p[2] = {7, 4};
    int c[2];
    int i, j;

    printf("Plaintext: HI\n");

    for(i = 0; i < 2; i++) {
        c[i] = 0;

        for(j = 0; j < 2; j++)
            c[i] += key[i][j] * p[j];

        c[i] %= 26;
    }

    printf("Ciphertext: ");

    for(i = 0; i < 2; i++)
        printf("%c", c[i] + 'A');

    printf("\nKnown Plaintext: HI");
    printf("\nKnown Ciphertext: TC");

    return 0;
}
