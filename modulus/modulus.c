#include <stdio.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[20];

    int n = 0, m = 0;

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        sscanf(line, "%d,%d", &n, &m);
        n -= (m * (int)(n/m));
        printf("%d\n", n);
    }

    fclose(file);

    return 0;
}
