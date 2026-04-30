#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_input(char *line) {
    int cap = 64;
    char **args = malloc(cap * sizeof(char *));
    int i = 0;
    char *tok = strtok(line, " \t");
    while (tok) {
        args[i++] = tok;
        tok = strtok(NULL, " \t");
    }
    args[i] = NULL;
    return args;
}

void free_args(char **args) {
    free(args);
}
