#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char plain[200], key[] = "CIPHER";
    char cipher[27];
    int i, j = 0, used[26] = {0};

    for (i = 0; key[i] != '\0'; i++)
    {
        char c = toupper(key[i]);
        if (!used[c - 'A'])
        {
            cipher[j++] = c;
            used[c - 'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++)
        if (!used[i])
            cipher[j++] = 'A' + i;

    cipher[26] = '\0';

    printf("Plaintext: ");
    fgets(plain, sizeof(plain), stdin);

    printf("Cipher alphabet: %s\n", cipher);
    printf("Ciphertext: ");

    for (i = 0; plain[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)plain[i]))
        {
            char c = toupper((unsigned char)plain[i]);
            printf("%c", cipher[c - 'A']);
        }
        else
            printf("%c", plain[i]);
    }

    return 0;
}
