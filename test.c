#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int pid;
    int rval;
    if ((pid = fork()) == 0) {
        printf("child pid = %d\n",pid);
        if ((pid = fork()) != 0) {
            printf("child child pid = %d\n",pid);
            sleep(5);
            return 10;
        }
    }
    while (1) {
        sleep(1);
        int res = waitpid(pid, &rval, WNOHANG);
        printf("parent pid = %d\n",pid);
        printf("Returned value %d\n", WEXITSTATUS(rval));
    }
}
