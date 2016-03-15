#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[20];
    int h1 = 0, m1 = 0, s1 = 0,
        h2 = 0, m2 = 0, s2 = 0,
        diff = 0;

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        sscanf(line, "%d:%d:%d %d:%d:%d\n", &h1, &m1, &s1, &h2, &m2, &s2);
        diff = abs(((h1 * 3600) + (m1 * 60) + s1) - ((h2 * 3600) + (m2 * 60) + s2));
        printf("%02d:%02d:%02d\n", diff / 3600, (diff / 60) % 60, diff % 60);
    }

    fclose(file);

    return 0;
}
