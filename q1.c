#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>



// testing
int main() {

    int  x = 100;

    int rc = fork();

    if (rc == 0) // This shows child
    {
        printf("---------------------\n");
        printf("Child process\n");
        printf("--------------------------\n");
        printf("Value of X: %d\n", x);
        x = 300;
        printf("the new value of x is : %d\n", x);
        
    }
    else if (rc > 0) // This shows parent
    {
        wait(NULL);
        printf("---------     -----------\n");
        printf("The Parent process \n");
        printf("----------------------------\n");
        printf("value  of X: %d\n", x);
        x = 400;
        printf("Modified  Value of x: %d\n", x);
    }
    else // this shows the eror
    {
        fprintf(stderr, "Error in  creating process");
    }
 
     return 0;

  
}

/**************************************************
Name: AbdulBaseer
Question 1: 
Ans) When we call fork(), it creats a copy of the parent process. 
   The child, and parent have their own specific addresses in the memory, and they don't interfare with
   each othe's momory space. Each maintain their own version of the variables.

******/
 
