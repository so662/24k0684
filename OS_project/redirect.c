#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void handle_redirection(char **args) {
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], "<") == 0) {
            int fd = open(args[i+1], O_RDONLY);
            if (fd < 0) { perror("open"); return; }
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[i] = args[i+1] = NULL;
        }
        if (args[i] && strcmp(args[i], ">") == 0) {
            int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) { perror("open"); return; }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i] = args[i+1] = NULL;
        }
        if (args[i] && strcmp(args[i], ">>") == 0) {
            int fd = open(args[i+1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd < 0) { perror("open"); return; }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i] = args[i+1] = NULL;
        }
    }
}

void execute_pipe(char **left, char **right) {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {          /* left child: writer */
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execvp(left[0], left);
        exit(1);
    }

    if (fork() == 0) {          /* right child: reader */
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execvp(right[0], right);
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
}
