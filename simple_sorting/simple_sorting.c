#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *x, const void *y) {
    if(*(const float *)x < *(const float *)y) {
        return -1;
    } else {
        return *(const float *)x > *(const float *)y;
    }
}

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

        int n_count = 0;
        float list[1024], n;
        char *n_string = strtok(line, " "), *nl_pos;

        do {
            // strip newline from string if needed
            if ((nl_pos = strpbrk(n_string, "\n"))) {
                *nl_pos = '\0';
            }
            sscanf(n_string, "%f", &n);
            list[n_count] = n;
            n_count++;
        } while ((n_string = strtok(NULL, " ")));

        qsort(list, n_count, sizeof(float), compare);

        for (int i = 0; i < n_count; i++) {
            printf("%.3f ", list[i]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
