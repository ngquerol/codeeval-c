#include <stdio.h>
#include <stdlib.h>
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
        char *p1 = line, *p2;
        int n = 0;

        // how many numbers is there ?
        while (*p1) {
            if (*p1 == ' ') {
                n++;
            }
            p1++;
        }

        // there is (number of spaces + 1) numbers to store
        int numbers[++n], i = 0;

        // parse the line to get all these numbers
        p2 = strtok(line, " ");
        do {
            numbers[i] = strtol(p2, &p2, 10);
            i++;
        } while ((p2 = strtok(NULL, " ")));

        // loop to detect cycle (tortoise & hare)
    }

    fclose(file);

    return 0;
}
