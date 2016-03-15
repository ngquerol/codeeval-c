#include <stdio.h>
#include <string.h>
#include <math.h>

long binary_to_decimal(const char *binary_str)
{
    int n, pos = strlen(binary_str) - 1;
    long sum = 0;
    const char *p = binary_str;

    while (*p) {
        sscanf(p, "%1d", &n);
        sum += n * pow(2, pos);
        p++;
        pos--;
    }
    return sum;
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
        char *flag = strtok(line, " ");
        char *seq  = strtok(NULL, " ");
        char *nl_pos;
        char binary[1024] = "";

        do {
            // Strip the newline if needed. We just look for a newline
            // in the sequence, as the line is normally terminated
            // with a sequence and not a flag.
            if ((nl_pos = strpbrk(seq, "\n")))
                *nl_pos = '\0';

            // Get the flag, and append length of seq times its value (0, 1)
            if (strcmp(flag, "00") == 0) {
                for (int i = 0; i < (int)strlen(seq); i++) {
                    strcat(binary, "1");
                }
            } else if (strcmp(flag, "0") == 0) {
                for (int i = 0; i < (int)strlen(seq); i++) {
                    strcat(binary, "0");
                }
            }
        } while ((flag = strtok(NULL, " ")) && (seq = strtok(NULL, " ")));

        // convert the binary string to a decimal number and print it
        printf("%ld\n", binary_to_decimal(binary));
    }

    fclose(file);

    return 0;
}
