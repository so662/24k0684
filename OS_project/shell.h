#ifndef SHELL_H
#define SHELL_H

char **parse_input(char *line);
void free_args(char **args);
void execute(char **args);
void handle_redirection(char **args);
void execute_pipe(char **left, char **right);
int run_builtin(char **args);
void add_history_entry(const char *cmd);
void print_history(void);
void setup_signals(void);

#endif
