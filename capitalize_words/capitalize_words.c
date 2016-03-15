#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

        // First character of the line
        if (isalpha(*p))
            *p = toupper(*p);

        // Advance p before the next word
        p = strchr(line, ' ');

        // Rest of the line
        while (p != NULL && *p) {
            if (isalpha(*p) && isspace(*(p - 1)))
                *p = toupper(*p);
            p++;
        }

        puts(line);
    }

    fclose(file);

    return 0;
}
