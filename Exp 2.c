#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], encrypted[100], decrypted[100];
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, j;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            encrypted[i] = key[ch - 'A'];
        }
        else
        {
            encrypted[i] = text[i];
        }
    }

    encrypted[i] = '\0';

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        if(isalpha(encrypted[i]))
        {
            char ch = toupper(encrypted[i]);

            for(j = 0; j < 26; j++)
            {
                if(key[j] == ch)
                {
                    decrypted[i] = 'A' + j;
                    break;
                }
            }
        }
        else
        {
            decrypted[i] = encrypted[i];
        }
    }

    decrypted[i] = '\0';

    printf("\nSubstitution Key: %s", key);
    printf("\nEncrypted Text: %s", encrypted);
    printf("Decrypted Text: %s", decrypted);

    return 0;
}
