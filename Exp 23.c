
#include <stdio.h>

int main() {
    int pt[] = {1, 2, 4};
    int key = 29;
    int counter = 0;
    int cipher[3];
    int i, stream;

    printf("CTR Encryption:\n");

    for(i = 0; i < 3; i++) {
        stream = counter ^ key;
        cipher[i] = pt[i] ^ stream;

        printf("Cipher block %d: %d\n",
               i + 1, cipher[i]);

        counter++;
    }

    printf("\nCTR Decryption:\n");
    counter = 0;

    for(i = 0; i < 3; i++) {
        stream = counter ^ key;
        printf("Plain block %d: %d\n",
               i + 1, cipher[i] ^ stream);
        counter++;
    }

    return 0;
}
