#include "diagnostics.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

// defaults
static char *progname = "unknown-program";
static int diaglevel = DIAG_ERROR;

void diag_set_level(char *prog, int level) {
    progname = prog;
    diaglevel = level;
}

void diag_print(int level, char *func, char *diag) {
    // get current time as string
    time_t now = time(NULL);
    char *now_string = ctime(&now);
    now_string[strlen(now_string) - 1] = '\0'; // remove newline

    fprintf(stderr, "%s - %s\n", now_string, diag);
}