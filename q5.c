#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int ab  = fork();
    
    if (ab == 0) // child
    {
        printf("I am child process. My PID is %d\n", getpid());
        exit(0);
    }
    else if (ab > 0)
    {
        int condition;
        waitpid(ab, &condition , 0);
        printf("hello,  I am the  parent process. My PID  is %d\n", getpid());        
    }
    else
    {
        fprintf(stderr, "Error may have  occurred during fork()");
    }
}

/* 
https://github.com/ahmedbilal/OSTEP-Solution/blob/master/Chapter%205/question7.c
*/

