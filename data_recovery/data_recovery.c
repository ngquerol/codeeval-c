// required for strtok_r
#define _GNU_SOURCE

#include <stdlib.h>
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
        char *sentence = strtok(line, ";");
        char *sequence = strtok(NULL, ";");
        char *saveptr1 = NULL, *saveptr2 = NULL;

        char *word = strtok_r(sentence, " ", &saveptr1);
        char *pos_str = strtok_r(sequence, " ", &saveptr2);
        char *reconstruct[64] = { NULL };

        int pos;

        // get each word from the shuffled sentence and number
        // sequence simultaneously.
        // then, put each word at the index it is supposed to be at
        // in a new array.
        do {
            sscanf(pos_str, "%d", &pos);
            // the sequence is indexed from 1
            reconstruct[pos - 1] = word;
        } while (((pos_str = strtok_r(NULL, " ", &saveptr2))) &&
                 ((word = strtok_r(NULL, " ", &saveptr1))));

        // as there is always one position missing in the sequence,
        // look for it in the reconstructed sentence, and put the
        // last word we have left at this index.
        for (int i = 0; i < 64; i++) {
            if (reconstruct[i] == '\0') {
                reconstruct[i] = strtok_r(NULL, " ", &saveptr1);
                break;
            }
        }

        // reuse pos to iterate over the reconstructed sentence
        // and print it.
        pos = 0;

        while (reconstruct[pos]) {
            printf("%s ", reconstruct[pos]);
            pos++;
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
