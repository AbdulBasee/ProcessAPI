#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int ab = fork();
    
    if (ab == 0) // child
    {
        printf("Hello, I am the  child process. My PID is %d\n", getpid());
        exit(0);
    }
    else if (ab > 0)
    {
        int condition;
        waitpid(ab, &condition, 0);
        printf("Hi, I am the  parent process. My PID  is %d\n", getpid());        
    }
    else
    {
        fprintf(stderr, "Error may have  occurred during fork()");
    }
}
