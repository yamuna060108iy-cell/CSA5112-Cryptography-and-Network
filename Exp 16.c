#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c[1000], result[1000];
    int freq[26] = {0}, order[26], i, j;
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char map[26];

    printf("Enter ciphertext: ");
    fgets(c, sizeof(c), stdin);

    for (i = 0; c[i]; i++)
        if (isalpha((unsigned char)c[i]))
            freq[toupper((unsigned char)c[i])-'A']++;

    for (i = 0; i < 26; i++) order[i] = i;

    for (i = 0; i < 26; i++)
        for (j = i+1; j < 26; j++)
            if (freq[order[j]] > freq[order[i]]) {
                int t = order[i];
                order[i] = order[j];
                order[j] = t;
            }

    for (i = 0; i < 26; i++)
        map[order[i]] = english[i];

    for (i = 0; c[i]; i++) {
        if (isalpha((unsigned char)c[i])) {
            char ch = toupper((unsigned char)c[i]);
            result[i] = map[ch-'A'];
        } else result[i] = c[i];
    }

    printf("Approximate plaintext: %s", result);
    return 0;
}
