#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1024];
    char buffer[1024] = { 0 };

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        const char *s = strtok(line, ",");
        const char *c = strtok(NULL, ",");
        int i = 0;

        while (*s) {
            if (!strchr(c, *s) || isspace(*s)) {
                buffer[i] = *s;
                i++;
            }
            s++;
        }
        printf("%s\n", buffer);
        // clear only the part of the buffer which has been
        // modified (much optimize, wow)
        memset(buffer, 0, strlen(buffer));
    }

    fclose(file);

    return 0;
}
