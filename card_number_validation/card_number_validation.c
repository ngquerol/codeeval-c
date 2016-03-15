#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE *file;
    char line[24];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        int length = strlen(line);

        if (length > 1) {
            char *card_number = line + length - 1;
            int n, digit_sum = 0, i = 0;

            while (*card_number) {
                // for each number
                if (!isspace(*card_number)) {
                    n = *card_number - '0';
                    // for each second number...
                    if (i % 2 != 0) {
                        // if this number * 2 > 9, add the sum of its
                        // digits to the total
                        if ((n * 2) > 9) {
                            digit_sum += ((n * 2) / 10) + ((n * 2) % 10);
                        } else {
                            // else just add this number * 2
                            digit_sum += n * 2;
                        }
                    } else {
                        // just add this number
                        digit_sum += n;
                    }
                    i++;
                }
                card_number--;
            }
            if (digit_sum % 10 == 0) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    fclose(file);
    return 0;
}
