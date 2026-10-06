#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a)
{
    int i;

    for(i = 1; i < 26; i++)
    {
        if((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    char text[100], encrypted[100], decrypted[100];
    int a, b, inv, i;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if(gcd(a, 26) != 1)
    {
        printf("Invalid value of a. It must be relatively prime to 26.");
        return 0;
    }

    inv = modInverse(a);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            encrypted[i] = ((a * (ch - 'A') + b) % 26) + 'A';
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
            int x = encrypted[i] - 'A';
            decrypted[i] = ((inv * (x - b + 26)) % 26) + 'A';
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
