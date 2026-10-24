#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock k1 = {1,2,3,4,5,6,7,8};
    DES_cblock k2 = {9,10,11,12,13,14,15,16};
    DES_cblock k3 = {17,18,19,20,21,22,23,24};
    DES_key_schedule s1, s2, s3;

    DES_cblock iv = {0,0,0,0,0,0,0,0};
    unsigned char in[8] = {'H','E','L','L','O','1','2','3'};
    unsigned char out[8];

    DES_set_key_unchecked(&k1, &s1);
    DES_set_key_unchecked(&k2, &s2);
    DES_set_key_unchecked(&k3, &s3);

    DES_ede3_cbc_encrypt(in, out, 8,
        &s1, &s2, &s3, &iv, DES_ENCRYPT);

    printf("Plaintext: HELLO123\n");
    printf("Ciphertext: ");
    for (int i = 0; i < 8; i++)
        printf("%02X", out[i]);
    printf("\n");

    return 0;
}
