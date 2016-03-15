#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[1024];
    char *reversed[128];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *nl_pos, *word = strtok(line, " ");
        int word_count = 0;

        // Store each pointer to each word of the line in an array,
        // and then loop through it from end to beginning.
        do {
            // Strip the newline from the word if need be
            if ((nl_pos = strpbrk(word, "\n"))) {
                *nl_pos = '\0';
            }
            reversed[word_count] = word;
            word_count++;
        } while ((word = strtok(NULL, " ")));

        while (word_count--) {
            printf("%s ", reversed[word_count]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
