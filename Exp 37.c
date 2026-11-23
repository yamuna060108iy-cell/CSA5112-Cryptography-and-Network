
#include <stdio.h>
#include <string.h>

int main() {
    char text[500];
    int freq[26] = {0};
    int i, j, max;
    char letters[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char map[26];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            freq[text[i] - 'A']++;
        else if(text[i] >= 'a' && text[i] <= 'z')
            freq[text[i] - 'a']++;
    }

    for(i = 0; i < 26; i++)
        map[i] = '?';

    printf("\nLetter Frequency:\n");

    for(i = 0; i < 26; i++)
        printf("%c : %d\n", 'A' + i, freq[i]);

    for(i = 0; i < 26; i++) {
        max = -1;

        for(j = 0; j < 26; j++) {
            if(freq[j] > max) {
                max = freq[j];
            }
        }

        if(max == 0)
            break;

        for(j = 0; j < 26; j++) {
            if(freq[j] == max) {
                map[j] = letters[i];
                freq[j] = -1;
                break;
            }
        }
    }

    printf("\nPossible Plaintext:\n");

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", map[text[i] - 'A']);
        else if(text[i] >= 'a' && text[i] <= 'z')
            printf("%c", map[text[i] - 'a']);
        else
            printf("%c", text[i]);
    }

    return 0;
}
