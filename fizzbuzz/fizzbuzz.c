#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(int x, int y, int n);
void fizzbuzz(int x, int y, int n) {
    int i = 0;

    for (i = 1; i <= n; i++) {
        if (i % x == 0 && i % y == 0) {
            printf("FB ");
        } else if (i % x == 0) {
            printf("F ");
        } else if (i % y == 0) {
            printf("B ");
        } else {
            printf("%i ", i);
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {

    FILE* file;
    char line[50];
    int x = 0, y = 0, n = 0;
    file = fopen(argv[1], "r");

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if (file == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        sscanf(line, "%i %i %i", &x, &y, &n);
        fizzbuzz(x, y, n);
    }

    fclose(file);

    return 0;
}
