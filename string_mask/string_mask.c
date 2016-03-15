#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[256];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char* str = strtok(line, " ");
        char* mask = strtok(NULL, " ");

        // str and mask are assumed to be of equal length
        for (int i = 0; i < (int)strlen(str); i++) {
            if (mask[i] == '1')
                printf("%c", toupper(str[i]));
            else
                printf("%c", str[i]);
        }

        printf("\n");
    }

    fclose(file);

    return 0;
}
