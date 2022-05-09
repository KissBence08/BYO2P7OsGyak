#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main()
{

    char* fifoname = "/tmp/BYO2P7";
    mkfifo(fifoname, 0666);

    int pipe;
    pid_t p;
 
    p = fork();
 
    if (p < 0) {
        fprintf(stderr, "fork hiba");
        return 1;
    } else if (p > 0) {
        char str[80];
 
        printf("parent process vár\n");

        wait(NULL);

        printf("parent process olvas\n");

        pipe = open(fifoname, O_RDONLY);
        read(pipe, str, 80);
        close(pipe);

        printf("%s piperól olvasva: %s\n", fifoname, str);
        
    }
    else { 
 
        printf("child process\n");

        char output_string[80];
        strcpy(output_string, "Kiss Bence\n");
     
        pipe = open(fifoname, O_WRONLY);
        write(pipe, output_string, strlen(output_string));
        close(pipe);

        printf("child process end\n");

        exit(0);
    }

    return 0;
}
