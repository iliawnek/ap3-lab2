#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int skip = 0; // if true, current arg is skipped

    for (int i = 0; i < argc; i++) {
        // skip and reset
        if (skip) {
            skip = 0;
            continue;
        }
        // skip "-diag level"
        else if (strcmp(argv[i], "-diag") == 0) {
            // error if no flag is given to -diag
            if (i == argc - 1) {
                printf("\nError: No argument given to -diag.\n");
                return -1;
            }
            skip = 1;
            continue;
        }
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
