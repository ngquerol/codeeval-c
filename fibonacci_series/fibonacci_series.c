#include <stdio.h>
#include <stdlib.h>

long long int nth_fibonacci_number_rec(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return nth_fibonacci_number_rec(n - 1) + nth_fibonacci_number_rec(n - 2);
    }
}

long long int nth_fibonacci_number(int n) {
    int n_now = 0, n_next = 1, n_temp;

    while (--n>0) {
        n_temp = n_now + n_next;
        n_now = n_next;
        n_next = n_temp;
    }
    return n_next;
}

int main(int argc, char** argv) {

    FILE* file;
    char line[80];
    file = fopen(argv[1], "r");

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if (file == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        int n;

        sscanf(line, "%d", &n);

        printf("%lld\n", nth_fibonacci_number(n));
    }

    fclose(file);

    return 0;
}
