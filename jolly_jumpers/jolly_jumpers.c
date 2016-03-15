#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LEN 10240 // we may have up to 3000 numbers, use a large buffer
#define NUM_SEP " "

int parse_seq_str(char* source_str, int* dest_array, int seq_len) {
    char* num_str = strtok(source_str, NUM_SEP);
    int parsed = 0;

    while (num_str && parsed < seq_len) {
        sscanf(num_str, "%d", &dest_array[parsed]);
        num_str = strtok(NULL, NUM_SEP);
        parsed++;
    }

    return parsed;
}

void get_intervals(const int* sequence, int seq_len, int *seen_intervals)        {
    for (int i = 1; i < seq_len; i++) {
        int diff = abs(sequence[i-1] - sequence[i]) - 1;
        if (diff < seq_len)
            seen_intervals[diff] = 1;
    }
}

int is_jolly(const int* seen_intervals, int len) {
    for (int i = 0; i < len; i++) {
        if (seen_intervals[i] == 0)
            return 0;
    }

    return 1;
}

int main(int argc, char** argv) {
    FILE* file;
    char line[LINE_MAX_LEN];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        int seq_len;
        char seq_len_str[4]; // sequence length is < 3000 -> 4 digits

        // extract sequence length from string
        sscanf(line, "%d ", &seq_len);
        sprintf(seq_len_str, "%d", seq_len);

        int sequence[seq_len], jolly;

        // parse the sequence, ignoring the previously extracted length
        // if the sequence's parsed length != the expected length, exit early
        if (parse_seq_str(line + strlen(seq_len_str), sequence, seq_len) != seq_len) {
            jolly = 0;
        } else {
            int intervals_len = seq_len == 1 ? 1 : seq_len - 1;
            int seen_intervals[intervals_len];

            for (int i = 0; i < intervals_len; i++) {
                seen_intervals[i] = 0;
            }

            get_intervals(sequence, seq_len, seen_intervals);

            jolly = is_jolly(seen_intervals, intervals_len);
        }

        jolly ? printf("Jolly\n") : printf("Not jolly\n");
    }

    fclose(file);

    return 0;
}
