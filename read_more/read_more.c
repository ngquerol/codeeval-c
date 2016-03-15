#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
        if (strlen(line) > 55) {
            char* read_more = "... <Read More>";
            char* p = line + 39; // p is now at the 40th character

            // Move p backwards to the first previous space
            // immediately following a word, so we don't truncate the
            // sentence mid-word
            while (*p) {
                if (isspace(*p) && !isspace(*(p-1))) {
                    break;
                }
                p--;
            }
            // If the line is made of only characters and no spaces,
            // the loop got out of the string. So, move back p to
            // the 41th character of the string.
            if (!*p) {
                p = line + 40;
            }

            // copy the "read more" string where the line has been
            // truncated (hence, the adress p points to)
            strncpy(p, read_more, strlen(read_more));
            // NUL-terminate the resulting string
            *(p + strlen(read_more)) = '\0';
            // Move back p to the beginning of the string, for
            // printing purposes
            p = line;
            printf("%s\n", p);
        } else {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}
