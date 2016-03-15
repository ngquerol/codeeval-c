#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TS_PER_LINE 20

typedef struct timestamp_t {
    int hours;
    int minutes;
    int seconds;
    int total_seconds;
} timestamp_t;

timestamp_t parse_timestamp(const char* input_str) {
    timestamp_t ts;
    sscanf(input_str, "%d:%d:%d", &ts.hours, &ts.minutes, &ts.seconds);
    ts.total_seconds = (ts.hours * 3600) + (ts.minutes * 60) + ts.seconds;
    return ts;
}

/* O(n) complexity (selection sort):
 * doesn't matter much in this case (input <= 20 timestamps)
 */
void sort_timestamps(timestamp_t* arr, int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        for (int j = i + 1; j < arr_len; j++) {
            if (arr[j].total_seconds > arr[i].total_seconds) {
                timestamp_t tmp = arr[i];
                arr[i] = arr[j];
                arr[j]= tmp;
            }
        }
    }
}

int main(int argc, char** argv) {

    FILE* file;
    char line[256];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char* ts_str = strtok(line, " ");
        timestamp_t ts_arr[MAX_TS_PER_LINE];
        int ts_count = 0;

        while (ts_str) {
            ts_arr[ts_count] = parse_timestamp(ts_str);
            ts_str = strtok(NULL, " ");
            ts_count++;
        }

        sort_timestamps(ts_arr, ts_count);

        for (int i = 0; i < ts_count; i++) {
            printf("%02d:%02d:%02d ",
                   ts_arr[i].hours, ts_arr[i].minutes, ts_arr[i].seconds);
        }

        printf("\n");
    }

    fclose(file);

    return 0;
}
