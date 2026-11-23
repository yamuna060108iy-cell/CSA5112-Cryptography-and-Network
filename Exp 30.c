#include <stdio.h>

int main() {
    int X, K, T, second, mac2;

    printf("Enter message block X: ");
    scanf("%d", &X);

    printf("Enter key value: ");
    scanf("%d", &K);

    T = X ^ K;

    second = X ^ T;

    mac2 = (X ^ K) ^ second ^ K;

    printf("One Block MAC: %d\n", T);
    printf("Second Block: %d\n", second);
    printf("Two Block MAC: %d\n", mac2);

    return 0;
}
