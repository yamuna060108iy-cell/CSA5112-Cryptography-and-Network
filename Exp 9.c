#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[100], text[1000], matrix[5][5];
int used[26];

void createMatrix()
{
    int i, j, k = 0;
    char c;

    for (i = 0; key[i]; i++)
    {
        c = toupper((unsigned char)key[i]);
        if (c == 'J') c = 'I';

        if (c >= 'A' && c <= 'Z' && !used[c - 'A'])
        {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }

    for (c = 'A'; c <= 'Z'; c++)
    {
        if (c == 'J') continue;

        if (!used[c - 'A'])
        {
            matrix[k / 5][k % 5] = c;
            used[c - 'A'] = 1;
            k++;
        }
    }
}

void decrypt(char a, char b)
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
        printf("%c%c", matrix[r1][(c1 + 4) % 5],
                       matrix[r2][(c2 + 4) % 5]);
    else if (c1 == c2)
        printf("%c%c", matrix[(r1 + 4) % 5][c1],
                       matrix[(r2 + 4) % 5][c2]);
    else
        printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
}

int main()
{
    int i, n = 0;
    char clean[1000];

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter ciphertext: ");
    scanf(" %999[^\n]", text);

    createMatrix();

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i]))
            clean[n++] = toupper((unsigned char)text[i]);

    if (n % 2 != 0)
    {
        printf("Invalid ciphertext length.\n");
        return 0;
    }

    clean[n] = '\0';

    printf("Decrypted plaintext: ");

    for (i = 0; i < n; i += 2)
        decrypt(clean[i], clean[i + 1]);

    printf("\n");
    return 0;
}
