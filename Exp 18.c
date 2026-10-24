#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t key = 0x133457799BBCDFF1ULL;
    uint64_t mask = (1ULL << 28) - 1;

    /* Illustration only: actual DES uses PC-1 first. */
    uint32_t C = (key >> 28) & mask;
    uint32_t D = key & mask;

    printf("Initial key: %016llX\n",
           (unsigned long long)key);
    printf("Illustrative C half: %07X\n", C);
    printf("Illustrative D half: %07X\n", D);
    printf("Each round subkey contains 48 bits.\n");
    printf("Actual DES requires PC-1, shifts and PC-2.\n");

    return 0;
}
