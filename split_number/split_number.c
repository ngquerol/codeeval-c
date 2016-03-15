#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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
        char* number_p = strtok(line, " "); // get the whole number
        char* pattern_p = strtok(NULL, " "); // get the whole pattern
        char operator;
        int left_number, left_number_length = 0,
            right_number, right_number_length = 0,
            result = 0;

        // determine the length of the left number
        while (isalpha(*pattern_p)) {
            pattern_p++;
            left_number_length++;
        }

        // extract it from the whole number
        char* left_number_string = malloc(left_number_length + 1);
        memcpy(left_number_string, number_p, left_number_length);
        // don't forget to NUL terminate the newly allocated string
        left_number_string[left_number_length] = '\0';
        // get the corresponding integer
        sscanf(left_number_string, "%d", &left_number);
        free(left_number_string);

        // since we now point at the operator, get it
        operator = *pattern_p;

        // move to the element next to the operator in the pattern
        pattern_p += 1;
        // move to what is now known to be the first element of the right number
        number_p += left_number_length;

        // repeat the same modus operandi for the right number
        // ( maybe put it in a function ?)
        while (isalpha(*pattern_p)) {
            pattern_p++;
            right_number_length++;
        }

        char *right_number_string = malloc(right_number_length + 1);
        memcpy(right_number_string, number_p, right_number_length);
        right_number_string[right_number_length] = '\0';
        sscanf(right_number_string, "%d", &right_number);
        free(right_number_string);

        // do the arithmetic operation that corresponds to the specified operator
        switch (operator) {
            case '+':
                result = left_number + right_number;
                break;

            case '-':
                result = left_number - right_number;
                break;
        }
        // and print the result !
        printf("%d\n", result);
    }

    fclose(file);

    return 0;
}
