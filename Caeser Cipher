#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], encrypted[100], decrypted[100];
    int key, i;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    key = key % 26;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            encrypted[i] = ((text[i] - 'A' + key) % 26) + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            encrypted[i] = ((text[i] - 'a' + key) % 26) + 'a';
        else
            encrypted[i] = text[i];
    }

    encrypted[i] = '\0';

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        if(encrypted[i] >= 'A' && encrypted[i] <= 'Z')
            decrypted[i] = ((encrypted[i] - 'A' - key + 26) % 26) + 'A';
        else if(encrypted[i] >= 'a' && encrypted[i] <= 'z')
            decrypted[i] = ((encrypted[i] - 'a' - key + 26) % 26) + 'a';
        else
            decrypted[i] = encrypted[i];
    }

    decrypted[i] = '\0';

    printf("\nEncrypted Text: %s", encrypted);
    printf("\nDecrypted Text: %s", decrypted);

    return 0;
}
