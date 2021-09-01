#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int kc = fork();

    if (kc == 0) // child
    {
        printf("* Running the  Child Process ****\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        // ***************** We can use one of the following optione ** /

        //execl("/bin/ls", "ls", NULL);
        //execlp("ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp);
        
        //execv("/bin/ls", argv);
        //execvp("ls", argv);
        //execvpe("ls", argv, envp); // 
        
    }
    else if (kc > 0) // Teh parent process
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error did occur  during the  fork()");
    }
}


/*
references
https://github.com/ahmedbilal/OSTEP-Solution/blob/master/Chapter%205/question4.c
*/
