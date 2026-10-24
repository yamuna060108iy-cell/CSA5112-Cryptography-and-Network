#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c[500], p[26][500];
    int score[26] = {0}, shift[26];
    int i, j, n;

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    printf("Number of candidates: ");
    scanf("%d", &n);

    for (i = 0; i < 26; i++) {
        shift[i] = i;
        for (j = 0; c[j] && c[j] != '\n'; j++) {
            if (isalpha((unsigned char)c[j])) {
                p[i][j] = (c[j]-'A'-i+26)%26+'A';
                if (strchr("ETAOINSHRDLU", p[i][j]))
                    score[i] += 2;
            } else {
                p[i][j] = c[j];
            }
        }
        p[i][j] = '\0';
    }

    for (i = 0; i < 26; i++)
        for (j = i+1; j < 26; j++)
            if (score[j] > score[i]) {
                int s = score[i];
                char temp[500];
                score[i] = score[j]; score[j] = s;
                s = shift[i]; shift[i] = shift[j]; shift[j] = s;
                strcpy(temp, p[i]);
                strcpy(p[i], p[j]); strcpy(p[j], temp);
            }

    if (n > 26) n = 26;
    for (i = 0; i < n; i++)
        printf("Shift %d: %s\n", shift[i], p[i]);

    return 0;
}
