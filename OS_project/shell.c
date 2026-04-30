#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void) {
    setup_signals();
    char input[1024];

    while (1) {
        printf("myshell> ");
        fflush(stdout);
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0) continue;

        add_history_entry(input);

        char **args = parse_input(input);
        if (args) {
            if (!run_builtin(args))
                execute(args);
            free_args(args);
        }
    }
    return 0;
}
