#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pids[10];
    int rval;
    if ((pids[0] = fork()) == 0) {
        sleep(5);
        exit(10);
    }
    int res = waitpid(pids[0], &rval, WNOHANG);
    while (1) {
        sleep(1);
        printf("child pid = %d\n",pids[0]);
        printf("Returned value %d\n", WEXITSTATUS(rval));
        printf("Returned value %d\n", WEXITSTATUS(rval));
        if (WEXITSTATUS(rval) == 10) {
            printf("Exiting\n");
            exit(0);
        }
    }
}
