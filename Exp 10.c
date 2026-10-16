#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void encrypt(char a, char b)
{
    int r1, c1, r2, c2, i, j;

    if (a == 'J') a = 'I';
    if (b == 'J') b = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == a)
            {
                r1 = i;
                c1 = j;
            }

            if (matrix[i][j] == b)
            {
                r2 = i;
                c2 = j;
            }
        }

    if (r1 == r2)
        printf("%c%c", matrix[r1][(c1 + 1) % 5],
                       matrix[r2][(c2 + 1) % 5]);
    else if (c1 == c2)
        printf("%c%c", matrix[(r1 + 1) % 5][c1],
                       matrix[(r2 + 1) % 5][c2]);
    else
        printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
}

int main()
{
    char text[500], clean[500], a, b;
    int i, n = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i]))
        {
            a = toupper((unsigned char)text[i]);
            clean[n++] = (a == 'J') ? 'I' : a;
        }

    clean[n] = '\0';

    printf("Encrypted ciphertext: ");

    for (i = 0; i < n; )
    {
        a = clean[i++];

        if (i == n)
            b = 'X';
        else if (clean[i] == a)
            b = 'X';
        else
            b = clean[i++];

        encrypt(a, b);
    }

    printf("\n");
    return 0;
}
