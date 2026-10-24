#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], cipher[200], plain[200];
    int a, b, c, d, i, j = 0;
    int inv[2][2] = {{7, 22}, {9, 9}};

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i]))
            text[j++] = toupper((unsigned char)text[i]);
    text[j] = '\0';

    if (j % 2) text[j++] = 'X';
    text[j] = '\0';

    printf("Ciphertext: ");
    for (i = 0; i < j; i += 2) {
        a = text[i] - 'A';
        b = text[i+1] - 'A';
        c = (9*a + 4*b) % 26;
        d = (5*a + 7*b) % 26;
        cipher[i] = c + 'A';
        cipher[i+1] = d + 'A';
    }
    cipher[j] = '\0';
    puts(cipher);

    printf("Decrypted text: ");
    for (i = 0; i < j; i += 2) {
        a = cipher[i] - 'A';
        b = cipher[i+1] - 'A';
        c = (inv[0][0]*a + inv[0][1]*b) % 26;
        d = (inv[1][0]*a + inv[1][1]*b) % 26;
        plain[i] = (c + 26) % 26 + 'A';
        plain[i+1] = (d + 26) % 26 + 'A';
    }
    plain[j] = '\0';
    puts(plain);

    return 0;
}
