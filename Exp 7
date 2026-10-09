#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000];
    int i;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Decrypted message: ");

    for (i = 0; cipher[i] != '\0'; i++)
    {
        switch (cipher[i])
        {
            case '5': printf("a"); break;
            case '3': printf("g"); break;
            case '0': printf("l"); break;
            case ')': printf("e"); break;
            case '6': printf("i"); break;
            case '*': printf("n"); break;
            case ';': printf("t"); break;
            case '4': printf("h"); break;
            case '8': printf("s"); break;
            case '2': printf("p"); break;
            case '.': printf("r"); break;
            case '9': printf("u"); break;
            case '1': printf("b"); break;
            case ' ': printf(" "); break;
            case '\n': printf("\n"); break;
            default: printf("%c", cipher[i]);
        }
    }

    return 0;
}
