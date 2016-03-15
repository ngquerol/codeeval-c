#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[80];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char* p = line;

        while (*p) {
            if (isalpha(*p))
                *p = tolower(*p);
            p++;
        }

        puts(line);
    }

    fclose(file);

    return 0;
}
