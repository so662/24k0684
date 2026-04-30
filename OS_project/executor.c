#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute(char **args) {
    // Pipe check
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], "|") == 0) {
            args[i] = NULL;
            char **right = &args[i+1];
            execute_pipe(args, right);
            return;
        }
    }

    // Background check
    int bg = 0, last = 0;
    while (args[last + 1]) last++;
    if (args[last] && strcmp(args[last], "&") == 0) {
        bg = 1;
        args[last] = NULL;
    }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return; }
    if (pid == 0) {
        /* child — redirection yahan hogi */
        handle_redirection(args);
        execvp(args[0], args);
        perror(args[0]);
        exit(1);
    } else {
        if (!bg) waitpid(pid, NULL, 0);
    }
}
