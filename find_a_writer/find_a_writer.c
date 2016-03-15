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
        char *name = strtok(line, "|");
        char *key = strtok(NULL, "|");
        char *pos_string = strtok(key, " ");
        int pos_n;

        do {
            sscanf(pos_string, "%d", &pos_n);
            printf("%c", name[pos_n - 1]);
        } while ((pos_string = strtok(NULL, " ")));

        printf("\n");
    }

    fclose(file);

    return 0;
}
