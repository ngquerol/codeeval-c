#include <stdio.h>
#include <string.h>

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
        const char delim_l[] = {'(', '[', '{'};
        const char delim_r[] = {')', ']', '}'};
        // use a stack data structure
    }

    fclose(file);

    return 0;
}
