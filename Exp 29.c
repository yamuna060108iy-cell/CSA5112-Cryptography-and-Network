#include <stdio.h>

int main() {
    int state = 1600;
    int block = 1024;
    int capacity;
    int lanes;
    int i;

    capacity = state - block;
    lanes = capacity / 64;

    printf("SHA-3 State Size: %d bits\n", state);
    printf("Block Size: %d bits\n", block);
    printf("Capacity: %d bits\n", capacity);

    printf("Capacity Lanes: %d\n", lanes);

    printf("\nInitial Capacity Lanes:\n");

    for(i = 0; i < lanes; i++)
        printf("Lane %d: 0\n", i + 1);

    printf("\nWithout permutation, capacity lanes ");
    printf("remain zero indefinitely.\n");

    return 0;
}
