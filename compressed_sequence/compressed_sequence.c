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
        char *s = strtok(line, " ");
        int n_occur = 0, n, n_old;

        sscanf(s, "%d", &n_old);

        do {
            sscanf(s, "%d", &n);
            if (n != n_old) {
                printf("%d %d ", n_occur, n_old);
                n_old = n;
                n_occur = 1;
            } else {
                n_occur++;
            }
        } while ((s = strtok(NULL, " ")));

        // print the last occurence count of n, as the loop exited
        // without doing it (it just incremented the counter)
        if (!s) {
            printf("%d %d ", n_occur, n_old);
        }

        printf("\n");
    }

    fclose(file);

    return 0;
}
