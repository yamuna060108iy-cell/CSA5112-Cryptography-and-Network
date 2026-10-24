#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[] = "SENDMOREMONEY";
    char target[] = "CASHNOTNEEDED";
    int key[] = {9,0,1,7,23,15,21,14,11,11,2,8,9};
    char c[14];
    int i;

    printf("Ciphertext: ");
    for (i = 0; i < 13; i++) {
        c[i] = (p[i] - 'A' + key[i]) % 26 + 'A';
        printf("%c", c[i]);
    }
    c[13] = '\0';

    printf("\nNew key stream: ");
    for (i = 0; i < 13; i++)
        printf("%d ", (c[i] - target[i] + 26) % 26);

    printf("\nNew key letters: ");
    for (i = 0; i < 13; i++)
        putchar((c[i] - target[i] + 26) % 26 + 'A');

    printf("\n");
    return 0;
}
