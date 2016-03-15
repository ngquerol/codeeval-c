#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[32];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        float number;
        int degrees, minutes, seconds;

        sscanf(line, "%f", &number);
        degrees = (int) number;
        number = (number - degrees) * 60;
        minutes = (int) number;
        number = (number - minutes) * 60;
        seconds = (int) number;

        printf("%d.%02d'%02d\"\n", degrees, minutes, seconds);
    }

    fclose(file);

    return 0;
}
