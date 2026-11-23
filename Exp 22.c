
#include <stdio.h>

int main() {
    int pt[2][8] = {
        {0,0,0,0,0,0,0,1},
        {0,0,1,0,0,0,1,1}
    };

    int key = 29;
    int iv = 170;
    int cipher[2];
    int previous = iv;
    int i, j, value;

    printf("CBC Encryption:\n");

    for(i = 0; i < 2; i++) {
        value = 0;

        for(j = 0; j < 8; j++)
            value = value * 2 + pt[i][j];

        cipher[i] = (value ^ previous) ^ key;
        previous = cipher[i];

        printf("Cipher block %d: ", i + 1);
        for(j = 7; j >= 0; j--)
            printf("%d", (cipher[i] >> j) & 1);
        printf("\n");
    }

    printf("\nCBC Decryption:\n");
    previous = iv;

    for(i = 0; i < 2; i++) {
        value = (cipher[i] ^ key) ^ previous;
        previous = cipher[i];

        printf("Plain block %d: ", i + 1);
        for(j = 7; j >= 0; j--)
            printf("%d", (value >> j) & 1);
        printf("\n");
    }

    return 0;
}
