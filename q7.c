#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ab  = fork();

    if (ab == 0) // child process
    {
        close(STDOUT_FILENO);
        printf("Hell, . are you able to see  this?\n");
    }
    else if (ab > 0)
    {
        wait(NULL);
        printf("I am parent process\n");
    }
    else 
    {
        printf("Error may have  occurred during fork()\n");
    }
}
