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
        float total = 0,
            lower = 0,
            upper = 0;

        while (*p) {
            if (isalpha(*p)) {
                total++;
                if (*p == toupper(*p)) {
                    upper++;
                } else {
                    lower++;
                }
            }
            p++;
        }
        printf("lowercase: %.2f uppercase: %.2f\n", (lower / total) * 100, (upper / total) * 100);
    }

    fclose(file);

    return 0;
}
