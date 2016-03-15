#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmpint(const void *x, const void *y) {
    int const *px = x;
    int const *py = y;

    return *px - *py;
}

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
        char *size_str = strtok(line, ";");
        char *list_str = strtok(NULL, ";");
        int size = strtol(size_str, &size_str, 10);
        int list[size];

        char *n = strtok(list_str, ",");
        int i = 0;
        do {
            list[i] = strtol(n, &n, 10);
            i++;
        } while ((n = strtok(NULL, ",")));

        qsort(list, sizeof list / sizeof *list, sizeof *list, cmpint);

        int *p1 = list;
        while (*p1 != *(p1 + 1)) {
            p1++;
        }
        printf("%d\n", *p1);
    }

    fclose(file);

    return 0;
}
