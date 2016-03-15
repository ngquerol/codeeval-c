#include <stdio.h>

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

        const char *zero[][1]  = {{"-**--"},
                                  {"*--*-"},
                                  {"*--*-"},
                                  {"*--*-"},
                                  {"-**--"},
                                  {"-----"}};

        const char *one[][1]   = {{"--*--"},
                                  {"-**--"},
                                  {"--*--"},
                                  {"--*--"},
                                  {"-***-"},
                                  {"-----"}};

        const char *two[][1]   = {{"***--"},
                                  {"---*-"},
                                  {"-**--"},
                                  {"*----"},
                                  {"****-"},
                                  {"-----"}};

        const char *three[][1] = {{"***--"},
                                  {"---*-"},
                                  {"-**--"},
                                  {"---*-"},
                                  {"***--"},
                                  {"-----"}};

        const char *four[][1]  = {{"-*---"},
                                  {"*--*-"},
                                  {"****-"},
                                  {"---*-"},
                                  {"---*-"},
                                  {"-----"}};

        const char *five[][1]  = {{"****-"},
                                  {"*----"},
                                  {"***--"},
                                  {"---*-"},
                                  {"***--"},
                                  {"-----"}};

        const char *six[][1]   = {{"-**--"},
                                  {"*----"},
                                  {"***--"},
                                  {"*--*-"},
                                  {"-**--"},
                                  {"-----"}};

        const char *seven[][1] = {{"****-"},
                                  {"---*-"},
                                  {"--*--"},
                                  {"-*---"},
                                  {"-*---"},
                                  {"-----"}};

        const char *eight[][1] = {{"-**--"},
                                  {"*--*-"},
                                  {"-**--"},
                                  {"*--*-"},
                                  {"-**--"},
                                  {"-----"}};

        const char *nine[][1]  = {{"-**--"},
                                  {"*--*-"},
                                  {"-***-"},
                                  {"---*-"},
                                  {"-**--"},
                                  {"-----"}};

        for (int i = 0; i < 6; i++) {

            char *p = line;

            while (*p) {
                // convert the char to an int (basically, remove the NUL
                // character directly following it)
                switch (*p - '0') {
                    case 0:
                        printf("%s", zero[i][0]);
                        break;

                    case 1:
                        printf("%s", one[i][0]);
                        break;

                    case 2:
                        printf("%s", two[i][0]);
                        break;

                    case 3:
                        printf("%s", three[i][0]);
                        break;

                    case 4:
                        printf("%s", four[i][0]);
                        break;

                    case 5:
                        printf("%s", five[i][0]);
                        break;

                    case 6:
                        printf("%s", six[i][0]);
                        break;

                    case 7:
                        printf("%s", seven[i][0]);
                        break;

                    case 8:
                        printf("%s", eight[i][0]);
                        break;

                    case 9:
                        printf("%s", nine[i][0]);
                        break;

                    default:
                        break;
                }
                p++;
            }
            printf("\n");
        }
    }

    fclose(file);

    return 0;
}
