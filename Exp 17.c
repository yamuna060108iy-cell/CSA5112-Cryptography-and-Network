#include <stdio.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = {0x13,0x34,0x57,0x79,
                      0x9B,0xBC,0xDF,0xF1};
    DES_cblock cipher = {0x85,0xE8,0x13,0x54,
                         0x0F,0x0A,0xB4,0x05};
    DES_cblock plain;
    DES_key_schedule ks;

    DES_set_key_unchecked(&key, &ks);
    DES_ecb_encrypt(&cipher, &plain, &ks, DES_DECRYPT);

    printf("Decrypted plaintext: ");
    for (int i = 0; i < 8; i++)
        printf("%02X", plain[i]);
    printf("\n");

    return 0;
}
