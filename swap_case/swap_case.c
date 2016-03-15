#include <stdio.h>
#include <ctype.h>

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
        char *p = line;

        while(*p) {
            /* Library version */
            /* if (isalpha(*p)) { */
            /*     *p == toupper(*p) ? (*p = tolower(*p)) : (*p = toupper(*p)); */
            /* } */

            // Get-our-hands-dirty version
            if (isalpha(*p)) {
                if (*p >= 'a' && *p <= 'z') {
                    *p = 'A' + *p - 'a';
                } else if (*p >= 'A' && *p <= 'Z') {
                    *p = 'a' + *p - 'A';
                }
            }
            p++;
        }
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
