
#include <stdio.h>
#include <string.h>

int main() {
    char pt[100], ct[100];
    int key[100], n, i;

    printf("Enter plaintext: ");
    scanf("%99s", pt);

    n = strlen(pt);

    printf("Enter %d key values (0-25): ", n);

    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for(i = 0; i < n; i++) {
        int p = pt[i] - 'A';
        ct[i] = ((p + key[i]) % 26) + 'A';
    }

    ct[n] = '\0';

    printf("Encrypted Text: %s\n", ct);

    return 0;
}
