
#include <stdio.h>
#include <string.h>

int main() {
    char pt[100];
    int key, iv, i, n;
    int ecb[100], cbc[100], cfb[100];

    printf("Enter plaintext: ");
    scanf("%99s", pt);

    printf("Enter key (0-255): ");
    scanf("%d", &key);

    printf("Enter IV (0-255): ");
    scanf("%d", &iv);

    n = strlen(pt);

    printf("\nECB Encryption: ");
    for(i = 0; i < n; i++) {
        ecb[i] = pt[i] ^ key;
        printf("%d ", ecb[i]);
    }

    printf("\nCBC Encryption: ");
    for(i = 0; i < n; i++) {
        cbc[i] = (pt[i] ^ iv) ^ key;
        iv = cbc[i];
        printf("%d ", cbc[i]);
    }

    iv = 0;
    printf("\nCFB Demonstration: ");
    for(i = 0; i < n; i++) {
        cfb[i] = pt[i] ^ (key ^ iv);
        iv = cfb[i];
        printf("%d ", cfb[i]);
    }

    printf("\n\nPadding prevents ambiguity between ");
    printf("messages with different lengths.");

    return 0;
}
