#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv) {

    int ret;
    struct stat fs;

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((ret = stat(argv[1], &fs))) {
        perror("stat failed");
        return 1;
    }

    printf("%ld\n", fs.st_size);

    return 0;
}
