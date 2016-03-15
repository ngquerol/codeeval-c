#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* file;
    file = fopen(argv[1], "r");
    char line[1024];
    char *slang[] = { ", yeah!",
                      ", this is crazy, I tell ya.",
                      ", can U believe this?",
                      ", eh?",
                      ", aw yea.",
                      ", yo.",
                      "? No way!",
                      ". Awesome!",
    };

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if (file == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {
        int replacements = -1;
        char *p = line;
        char s[1024] = "";

        while (*p && *(p+1) != '\n') {
            if ((*p == '.' || *p == '?' || *p == '!')) {
                replacements = (replacements + 1) % 8;
                strncat(s, line, p - line);
                strcat(s, slang[replacements]);
                p++;
            }
            p++;
        }
        printf("%s\n", s);
    }

    fclose(file);

    return 0;
}
