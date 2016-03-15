#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    FILE* file;
    char line[30 * 1000];
    int sequence[30 * 1000] = { 0 };

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {

        // build the sequence array
        int len = 0, n;
        char *p = strtok(line, ",");

        do {
            sscanf(p, "%d", &n);
            sequence[len] = n;
            len++;
        } while ((p = strtok(NULL, ",")));

        // count the occurences of each element in the sequence, and
        // exit the loop early if we find the major element (there can
        // only be one)
        int count = 0, major = len / 2;

        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (sequence[i] == sequence[j]) {
                    count++;
                }
            }
            if (count > major) {
                printf("%d\n", sequence[i]);
                break;
            }
            count = 0;
        }
        // count equals 0 if no major element was found
        if (count == 0) {
            printf("None\n");
        }
    }

    fclose(file);

    return 0;
}
