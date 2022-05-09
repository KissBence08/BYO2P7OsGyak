#include<stdio.h>
#include<signal.h>
#include <stdlib.h>

int sigintCount = 0;

void handleSignals(int sig) {
    if (sig == 3) {
        printf("SIGQUIT\n");
        exit(0);
    } else if (sig == 2) {
        if (sigintCount == 0) {
            printf("SIGINT\n");
            sigintCount++;
            signal(SIGINT, SIG_DFL);
        }
    }
}

int main()
{
    signal(SIGINT, handleSignals);
    signal(SIGQUIT, handleSignals);
    while (1) ;
    return 0;
}
