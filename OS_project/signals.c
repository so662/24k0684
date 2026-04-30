#include <signal.h>
#include <stdio.h>

void sigint_handler(int sig) {
    (void)sig;
    printf("\n");
}

void setup_signals(void) {
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, SIG_IGN);
}
