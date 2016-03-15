#include <stdio.h>

int main() {

    int i = 0, j = 0, n = 1;

    for (i = 0; i < 12; i++) {
        for (j = 1; j <= 12; j++) {
            printf("%4i", (n + i) * j);
        }
        printf("\n");
    }

    return 0;
}
