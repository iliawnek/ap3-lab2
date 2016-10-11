#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "diagnostics.h"

int main(int argc, char* argv[]) {
    int is_diag_arg = 0; // if true, current arg is skipped

    for (int i = 0; i < argc; i++) {
        // skip and reset
        if (is_diag_arg) {
            diag_set_level("echo", atoi(argv[i]));
            is_diag_arg = 0;
            continue;
        }
        // skip "-diag level"
        else if (strcmp(argv[i], "-diag") == 0) {
            // error if no flag is given to -diag
            if (i == argc - 1) {
                printf("\nError: No argument given to -diag.\n");
                return -1;
            }
            is_diag_arg = 1;
            continue;
        }
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    diag_print(1, "lol", "haha");
    return 0;
}
