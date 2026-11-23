#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = {
        0x13, 0x34, 0x57, 0x79,
        0x9B, 0xBC, 0xDF, 0xF1
    };

    DES_key_schedule schedule;

    DES_cblock input = {
        0x01, 0x23, 0x45, 0x67,
        0x89, 0xAB, 0xCD, 0xEF
    };

    DES_cblock encrypted, decrypted;

    DES_set_key_unchecked(&key, &schedule);

    DES_ecb_encrypt(&input, &encrypted,
                    &schedule, DES_ENCRYPT);

    DES_ecb_encrypt(&encrypted, &decrypted,
                    &schedule, DES_DECRYPT);

    printf("Encrypted Data: ");

    for(int i = 0; i < 8; i++)
        printf("%02X", encrypted[i]);

    printf("\nDecrypted Data: ");

    for(int i = 0; i < 8; i++)
        printf("%02X", decrypted[i]);

    return 0;
}
