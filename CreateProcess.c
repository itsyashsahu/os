#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        // failed to fork
        fprintf(stderr, "Failed to fork ");
        exit(-1);
    }
    else if (pid == 0)
    {
        //  child process
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        // parent process
        wait(NULL);
        printf(" Child Process Ended");
        exit(0);
    }
}