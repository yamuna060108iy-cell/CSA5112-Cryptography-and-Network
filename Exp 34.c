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

    // ECB Encryption
    printf("\nECB Encryption: ");
    for(i = 0; i < n; i++) {
        ecb[i] = pt[i] ^ key;
        printf("%d ", ecb[i]);
    }

    // CBC Encryption
    printf("\nCBC Encryption: ");
    for(i = 0; i < n; i++) {
        cbc[i] = (pt[i] ^ iv) ^ key;
        iv = cbc[i];
        printf("%d ", cbc[i]);
    }

    // CFB Encryption
    iv = 0;
    printf("\nCFB Encryption: ");
    for(i = 0; i < n; i++) {
        cfb[i] = pt[i] ^ (key ^ iv);
        iv = cfb[i];
        printf("%d ", cfb[i]);
    }

    printf("\n\nPadding is used to make plaintext ");
    printf("fit the required block size.\n");

    return 0;
}
