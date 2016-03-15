#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1000];

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
        int i = 0;

        while (*p) {
            if (isalpha(*p)) {
                if (i % 2 == 0) {
                    *p = toupper(*p);
                }
                i++;
            }
            p++;
        }
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
