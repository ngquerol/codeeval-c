#include <stdio.h>
#include <ctype.h>
#include <string.h>

// swap two ints of an array, each at a specified position.
void swap(int *array, int pos1, int pos2) {
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
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
        char *sequence_str = strtok(line,  ":");
        char *swaps_list = strtok(NULL, ":");

        // build the sequence array from the string
        int sequence[1024], n, n_count = 0;
        char *number_str = strtok(sequence_str, " ");
        do {
            sscanf(number_str, "%d", &n);
            sequence[n_count] = n;
            n_count++;
        } while ((number_str = strtok(NULL, " ")));

        // do the swap for each pair of positions found
        int pos1, pos2;
        char *swap_pair = strtok(swaps_list, ", ");
        do {
            sscanf(swap_pair, "%d-%d", &pos1, &pos2);
            swap(sequence, pos1, pos2);
        } while ((swap_pair = strtok(NULL, ", ")));

        // print the resulting array
        for (int i = 0; i < n_count; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
