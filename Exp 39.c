#include <stdio.h>
#include <string.h>

int main() {
    char text[500];
    int i, shift;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("\nPossible Plaintexts:\n");

    for(shift = 0; shift < 26; shift++) {
        printf("\nShift %d: ", shift);

        for(i = 0; text[i] != '\0'; i++) {
            if(text[i] >= 'A' && text[i] <= 'Z')
                printf("%c",
                (text[i] - 'A' - shift + 26) % 26 + 'A');

            else if(text[i] >= 'a' && text[i] <= 'z')
                printf("%c",
                (text[i] - 'a' - shift + 26) % 26 + 'a');

            else
                printf("%c", text[i]);
        }
    }

    return 0;
}
