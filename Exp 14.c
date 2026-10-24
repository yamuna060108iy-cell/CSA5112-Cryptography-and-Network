#include <stdio.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int main() {
    int p[2][2] = {{7, 0}, {8, 19}};
    int c[2][2], k[2][2];
    int i, j;

    /* Encrypt plaintext pairs HI and AT */
    for (j = 0; j < 2; j++) {
        c[0][j] = mod26(9*p[0][j] + 4*p[1][j]);
        c[1][j] = mod26(5*p[0][j] + 7*p[1][j]);
    }

    /* P inverse modulo 26 = {{13, 0}, {12, 17}} */
    int pinv[2][2] = {{13, 0}, {12, 17}};

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            k[i][j] = mod26(
                c[i][0]*pinv[0][j] +
                c[i][1]*pinv[1][j]);

    printf("Recovered key matrix:\n");
    for (i = 0; i < 2; i++)
        printf("%d %d\n", k[i][0], k[i][1]);

    return 0;
}
