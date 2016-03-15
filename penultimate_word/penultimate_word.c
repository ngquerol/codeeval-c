#include <stdio.h>
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

        char* token;
        char* p = line;
        int i = 0;

        // We count how many spaces there is between the words.
        while (*p) {
            if (*p == ' ')
                i++;
            p++;
        }

        // We extract the first word.
        token = strtok(line, " ");

        // If there is only one space, then we already are on the
        // penultimate word, and so we already extracted it.
        // If not, we take the next one until we find it.
        // If the line was empty, don't do anything.
        while (token != NULL && i > 1) {
            token = strtok(NULL, " ");
            i--;
        }

        printf("%s\n", token);
    }

    fclose(file);

    return 0;
}
