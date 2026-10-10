#include <stdio.h>
#include <ctype.h>

int main()
{
    char cipher[1000];
    int i, a = 3, b = 15, inverse = 9;
    int value;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Decrypted plaintext: ");

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)cipher[i]))
        {
            value = toupper((unsigned char)cipher[i]) - 'A';
            value = (inverse * (value - b + 26)) % 26;

            printf("%c", value + 'A');
        }
        else
        {
            printf("%c", cipher[i]);
        }
    }

    printf("\n");
    return 0;
}
