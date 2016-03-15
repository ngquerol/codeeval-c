#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[50];
    int x, ones;
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
        sscanf(line, "%d", &x);
        ones = 0;

        do {
            if (x % 2 == 1) {
                ones++;
            }
        } while ((x /= 2) != 0);

        printf("%d\n", ones);
    }

    fclose(file);

    return 0;
}
