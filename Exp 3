#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    char encrypted[100], decrypted[100];
    int i, j = 0, keyLen;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    keyLen = strlen(key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char p = toupper(text[i]);
            char k = toupper(key[j % keyLen]);

            encrypted[i] = ((p - 'A' + k - 'A') % 26) + 'A';
            j++;
        }
        else
        {
            encrypted[i] = text[i];
        }
    }

    encrypted[i] = '\0';

    j = 0;

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        if(isalpha(encrypted[i]))
        {
            char c = encrypted[i];
            char k = toupper(key[j % keyLen]);

            decrypted[i] = ((c - 'A' - (k - 'A') + 26) % 26) + 'A';
            j++;
        }
        else
        {
            decrypted[i] = encrypted[i];
        }
    }

    decrypted[i] = '\0';

    printf("\nEncrypted Text: %s", encrypted);
    printf("Decrypted Text: %s", decrypted);

    return 0;
}
