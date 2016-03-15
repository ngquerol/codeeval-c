#include <stdio.h>
#include <string.h>
#include <math.h>

// The number of cycles where the sum we found is not equal to 1.
// Past this number of iterations, we give up and say the
// given number is not a happy number.
#define ITER_MAX 100

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
        int sum = 0, iter = 0;

        while (sum != 1 && iter < ITER_MAX) {
            char *s = line;
            int n;
            sum = 0;

            while (*s && *s != '\n') {
                sscanf(s, "%1d", &n);
                sum += pow(n, 2);
                s++;
            }
            // store the string representation of the sum we just
            // calculated, to repeat the process
            sprintf(line, "%d", sum);
            iter++;
        }
        sum == 1 ? puts("1") : puts("0");
    }

    fclose(file);

    return 0;
}
