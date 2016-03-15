#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[100];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *message;
        char *c;
        int index;

        message = strtok(line, ",");
        c = strtok(NULL, ",");

        char *rightmost_c = strrchr(message, *c);
        index = rightmost_c ? rightmost_c - message : -1;

        printf("%d\n", index);
    }

    fclose(file);

    return 0;
}
