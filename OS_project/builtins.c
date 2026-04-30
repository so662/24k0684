#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HIST_SIZE 100
static char *history[HIST_SIZE];
static int hist_count = 0;

void add_history_entry(const char *cmd) {
    if (hist_count < HIST_SIZE)
        history[hist_count++] = strdup(cmd);
}

void print_history(void) {
    for (int i = 0; i < hist_count; i++)
        printf("%3d  %s\n", i + 1, history[i]);
}

int run_builtin(char **args) {
    if (!args[0]) return 0;

    if (strcmp(args[0], "exit") == 0) exit(0);

    if (strcmp(args[0], "pwd") == 0) {
        char buf[1024];
        if (getcwd(buf, sizeof(buf)))
            printf("%s\n", buf);
        return 1;
    }

    if (strcmp(args[0], "cd") == 0) {
        char *path = args[1] ? args[1] : getenv("HOME");
        if (args[1] && strcmp(args[1], "~") == 0)
            path = getenv("HOME");
        if (chdir(path) != 0) perror("cd");
        return 1;
    }

    if (strcmp(args[0], "history") == 0) {
        print_history();
        return 1;
    }

    if (strcmp(args[0], "help") == 0) {
        printf("Built-in commands: cd, pwd, exit, history, help\n");
        return 1;
    }

    return 0;
}
