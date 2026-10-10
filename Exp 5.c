#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void process(char text[], char result[], int encrypt)
{
    int i, pos = 0;
    int r1, c1, r2, c2;
    char a, b;

    for(i = 0; text[i] != '\0'; )
    {
        if(!isalpha(text[i]))
        {
            i++;
            continue;
        }

        a = toupper(text[i++]);

        if(a == 'J')
            a = 'I';

        while(text[i] != '\0' && !isalpha(text[i]))
            i++;

        if(text[i] == '\0')
        {
            b = 'X';
        }
        else
        {
            b = toupper(text[i]);

            if(b == 'J')
                b = 'I';

            if(a == b)
            {
                b = 'X';
            }
            else
            {
                i++;
            }
        }

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if(r1 == r2)
        {
            if(encrypt)
            {
                c1 = (c1 + 1) % 5;
                c2 = (c2 + 1) % 5;
            }
            else
            {
                c1 = (c1 + 4) % 5;
                c2 = (c2 + 4) % 5;
            }
        }
        else if(c1 == c2)
        {
            if(encrypt)
            {
                r1 = (r1 + 1) % 5;
                r2 = (r2 + 1) % 5;
            }
            else
            {
                r1 = (r1 + 4) % 5;
                r2 = (r2 + 4) % 5;
            }
        }
        else
        {
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }

        result[pos++] = matrix[r1][c1];
        result[pos++] = matrix[r2][c2];
    }

    result[pos] = '\0';
}

int main()
{
    char key[100], text[100];
    char encrypted[200], decrypted[200];
    int i, j;

    printf("Enter the key: ");
    scanf("%s", key);

    getchar();

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    process(text, encrypted, 1);
    process(encrypted, decrypted, 0);

    printf("\nEncrypted Text: %s", encrypted);
    printf("\nDecrypted Text: %s", decrypted);

    return 0;
}
