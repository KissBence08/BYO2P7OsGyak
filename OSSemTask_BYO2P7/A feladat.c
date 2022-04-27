#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int parent, child1, child2, grandchild1, grandchild2, grandchild3, grandchild4;

    child1 = fork();

    if (child1 == 0) {
        grandchild1 = fork();

        if (grandchild1 == 0) {
            sleep(2);
        }

        else {
            grandchild2 = fork();
            if (grandchild2 == 0) {
                sleep(2);
            }

            else {
                sleep(2);
            }
            sleep(2);
        }

        if (grandchild1 != 0) {
            wait(NULL);
        }
    }

    else {
        child2 = fork();

        if (child2 == 0) {
            grandchild3 = fork();

            if (grandchild3 == 0) {
                sleep(2);
            }

            else {
                grandchild4 = fork();
                if (grandchild4 == 0) {
                    sleep(2);
                }

                else {
                    sleep(2);
                }
                sleep(2);
            }
            
            if (grandchild3 != 0) {
                wait(NULL);
            }
        }

        else {
            if (child1 != 0) {
            wait(NULL);
            }
        }
    }
    return 0;
}