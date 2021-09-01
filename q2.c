#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    struct stat sb;
    int file  = open("greetin.txt", O_CREAT | O_RDWR, S_IRWXU);
    
    int wa = fork();

    if (wa  == 0)
    {
        const char * child_msg = "Hi, I am child process.  Writing on you\n";
        printf("******* Child  process writing on file ************\n");
        write(file, child_msg , strlen(child_msg));
        exit(0);
    }
    else if (wa > 0)
    {
        wait(NULL);
        const char * prntMsg = "Hello, I am parent process. Writing on you\n";
        printf("************ Parent process writing on file ************\n");
        write(file, prntMsg, strlen(prntMsg));
    }
    sync();
    fstat(file, &sb);
    lseek(file, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(file, buffer, sb.st_size);

    printf("Content of file: \n%s", buffer);
    close(file);
    return 0;
}

/*********************************************
Your name:
Question 2:  
ans) Yes, when a fork call happens, the file descriptor value in both of the processes are the same. The 
*********************************************/


/****
References
***/
/**********
https://github.com/ahmedbilal/OSTEP-Solution/blob/master/Chapter%205/question2.c
******************/
