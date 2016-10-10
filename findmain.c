#include <stdio.h>
#include "string.h"
#define MAXLINE 1000 /* maximum input line length */
#define USAGE "Usage: ./find [-x] pattern\n" /* message when incorrectly used */
#define TRUE 1
#define FALSE 0

/* print all lines from standard input that match pattern */
int main(int argc, char* argv[]) {
    /* detect incorrect number of arguments */
    if (argc < 2 || argc > 3) {
        printf(USAGE);
        return -1;
    }

    char* pattern; /* pattern to search for */
    int exclude = FALSE;

    if (argc == 2) {
        /* error if only flag is given */
        if (strcmp(argv[1], "-x") == 0) {
            printf(USAGE);
            return -2;
        }
        pattern = argv[1];
    }
    else if (argc == 3) {
        /* error if 1st of 2 args is not flag */
        if (strcmp(argv[1], "-x") != 0) {
            printf(USAGE);
            return -3;
        }
        exclude = TRUE;
        pattern = argv[2];
    }

    char line[MAXLINE];
    int found = 0;
    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (strstr(line, pattern) != NULL) {
            if (!exclude) {
                printf("%s", line);
            }
            found++;
        } else if (exclude) {
            printf("%s", line);
        }

    }
    return found;
}
