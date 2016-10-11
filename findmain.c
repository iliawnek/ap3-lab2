#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define MAXLINE 1000 // maximum input line length
#define USAGE "Usage: ./find [-x] pattern [pattern] ...\n" // message when incorrectly used
#define TRUE 1
#define FALSE 0

char *tolowerstring(char *string) {
    char *copy = (char*) malloc(strlen(string));
    strcpy(copy, string);
    for (int i = 0; i < strlen(copy); i++) {
        copy[i] = (char) tolower(copy[i]);
    }
    return copy;
}

// print all lines from standard input that match pattern
int main(int argc, char *argv[]) {
    // error if no args found
    if (argc < 2) {
        printf("Error: No arguments.\n");
        printf(USAGE);
        return -1;
    }

    int exclude = FALSE;
    int case_insensitive = FALSE;

    // check if flags are given
    if (strchr(argv[1], '-') != NULL) {
        // error if only flag is given
        if (argc < 3) {
            printf("Error: No patterns.\n");
            printf(USAGE);
            return -1;
        }
        // handle exclude flag
        if (strchr(argv[1], 'x') != NULL) {
            exclude = TRUE;
        }
        // handle case insensitivity flag
        if (strchr(argv[1], 'c') != NULL) {
            case_insensitive = TRUE;
        }
    }

    char line[MAXLINE];
    int found = 0;
    char *pattern;

    while (fgets(line, MAXLINE, stdin) != NULL) {
        for (int i = exclude ? 2 : 1; i < argc; i++) {
            pattern = case_insensitive ? tolowerstring(argv[i]) : argv[i];
            if (strstr(case_insensitive ? tolowerstring(line) : line, pattern) != NULL) {
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
