#include <stdio.h>
#include "string.h"

#define MAXLINE 1000 /* maximum input line length */
#define USAGE "Usage: ./find [-x] pattern [pattern] ...\n" /* message when incorrectly used */
#define TRUE 1
#define FALSE 0

/* print all lines from standard input that match pattern */
int main(int argc, char *argv[]) {
    /* error if no args found */
    if (argc < 2) {
        printf("Error: No arguments.\n");
        printf(USAGE);
        return -1;
    }

    /* check for flag */
    int exclude = FALSE;
    if (strcmp(argv[1], "-x") == 0) { /* if flag is present */
        /* error if only flag is given */
        if (argc < 3) {
            printf("Error: No patterns.\n");
            printf(USAGE);
            return -1;
        }
        exclude = TRUE;
    }

    char line[MAXLINE];
    int found = 0;
    char *pattern;
    int i;
    while (fgets(line, MAXLINE, stdin) != NULL) {
        for (i = exclude ? 2 : 1; i < argc; i++) {
            pattern = argv[i];
            if (strstr(line, pattern) != NULL) {
                if (!exclude) {
                    printf("%s", line);
                }
                found++;
                break; // skip to next line once first match is found
            } else if (exclude && i == argc - 1) {
                printf("%s", line); // only print if pattern is last argument
            }
        }
    }
    return found;
}
