#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[20];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *p = line;
        int digit, sum = 0;

        while (*p && *p != '\n') {
            sscanf(p, "%1d", &digit);
            sum += digit;
            p++;
        }
        printf(" %d\n", sum);
    }

    fclose(file);

    return 0;
}
