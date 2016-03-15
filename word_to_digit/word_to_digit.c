#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1024];
    char *numbers[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *s = strtok(line, ";");

        do {
            // Replace the newline with NUL if need be, as strtok does
            // not discard it.
            char *newline = strchr(s, '\n');
            if (newline) {
                *newline = '\0';
            }

            for (int i = 0; i < 10; i++) {
                if (strcmp(s, numbers[i]) == 0) {
                    printf("%d", i);
                    break;
                }
            }
        } while((s = strtok(NULL, ";")));
        printf("\n");
    }

    fclose(file);

    return 0;
}
