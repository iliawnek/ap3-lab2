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
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // remove newline
    char* diaglevelstring;
    switch (diaglevel) {
        case 0:
            diaglevelstring = "ERROR";
            break;
        case 1:
            diaglevelstring = "FUNCTION";
            break;
        case 2:
            diaglevelstring = "APPLICATION";
            break;
        case 3:
            diaglevelstring = "VERBOSE";
            break;
        default:
            diaglevelstring = "ERROR";
            break;
    }

    fprintf(stderr, "\n[%s] %s %s (%s): %s\n", timestamp, diaglevelstring, progname, func, diag);
}