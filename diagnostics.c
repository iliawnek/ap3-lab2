#include "diagnostics.h"
#include <stdio.h>

// the following static variables, visible to other functions in this
// file, are initialized here so that diag_print can be used even if
// no-one invokes diag_set_level
static char *progname = "unknown-program";
static int diaglevel = DIAG_ERROR;

void diag_set_level(char *prog, int level) {
    progname = prog;
    diaglevel = level;
}

void diag_print(int level, char *func, char *diag) {
// just prints the third argument for now, regardless of level
    fprintf(stderr, "%s\n", diag);
}