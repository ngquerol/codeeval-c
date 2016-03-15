#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1024];

    struct T_Point {
        int x;
        int y;
    } typedef T_Point;

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        T_Point a, b;
        sscanf(line, "(%d,%d) (%d,%d)", &a.x, &a.y, &b.x, &b.y);
        printf("%d\n", (int)sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
    }

    fclose(file);

    return 0;
}
