#include <stdio.h>
#include <string.h>

void SetRow(int (*board)[256], int row, int value) {
    for (int i = 0; i < 256; i++) {
        board[row][i] = value;
    }
}

void SetCol(int (*board)[256], int col, int value) {
    for (int i = 0; i < 256; i++) {
        board[i][col] = value;
    }
}

void QueryRow(const int (*board)[256], int row) {
    int sum = 0;

    for (int i = 0; i < 256; i++) {
        sum += board[row][i];
    }
    printf("%d\n", sum);
}

void QueryCol(const int (*board)[256], int col) {
    int sum = 0;

    for (int i = 0; i < 256; i++) {
        sum += board[i][col];
    }
    printf("%d\n", sum);
}

int main(int argc, char** argv) {

    FILE* file;
    char line[80];
    const char *op[] = { "SetRow", "SetCol", "QueryRow", "QueryCol" };
    int board[256][256] = { { 0 } };

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        char *query = strtok(line, " ");
        char *coord = strtok(NULL, "\n");

        if (strcmp(query, op[0]) == 0) {
            int i, x;
            sscanf(coord, "%d %d", &i, &x);
            SetRow(board, i, x);
        } else if (strcmp(query, op[1]) == 0) {
            int j, x;
            sscanf(coord, "%d %d", &j, &x);
            SetCol(board, j, x);
        } else if (strcmp(query, op[2]) == 0) {
            int i;
            sscanf(coord, "%d", &i);
            QueryRow(board, i);
        } else if (strcmp(query, op[3]) == 0) {
            int j;
            sscanf(coord, "%d", &j);
            QueryCol(board, j);
        }
    }

    fclose(file);

    return 0;
}
