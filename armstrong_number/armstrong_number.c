#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1024];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *nl = strpbrk(line, "\n");
        *nl = '\0';
        char *p = line;
        int len = strlen(line), sum = 0, n, number;

        sscanf(line, "%d", &number);

        while (*p) {
            sscanf(p, "%1d", &n);
            sum += pow(n, len);
            p++;
        }

        if (sum == number) {
            puts("True");
        } else {
            puts("False");
        }
    }

    fclose(file);

    return 0;
}
