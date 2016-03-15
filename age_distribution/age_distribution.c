#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    FILE* file;
    char line[20];
    int age = 0;

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        sscanf(line, "%d", &age);

        if (age >= 0 && age <= 2) {
            puts("Still in Mama's arms");
        } else if (age >= 3 && age <= 4) {
            puts("Preschool Maniac");
        } else if (age >= 5 && age <= 11) {
            puts("Elementary school");
        } else if (age >= 12 && age <= 14) {
            puts("Middle school");
        } else if (age >= 15 && age <= 18) {
            puts("High school");
        } else if (age >= 19 && age <= 22) {
            puts("College");
        } else if (age >= 23 && age <= 65) {
            puts("Working for the man");
        } else if (age >= 66 && age <= 100) {
            puts("The Golden Years");
        } else {
            puts("This program is for humans");
        }
    }

    fclose(file);

    return 0;
}
