#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSZE 32



int
main(int argc, char *argv[])
{
    // Setup our pipe
    char buff[BUFSZE];
    int  ar[2];

    if (pipe(p) < 0)
      exit(1);

    int ab  = fork();
    if (ab < 0) {
        
                       // in case the fork fails

        fprintf(stderr, "The first fork has  failed\n");
        exit(1);
    } else if (ab == 0) {
	                      // First child
       printf(" Child #1 ");
       close(ar[0]);                                 
       dup2(ar[1], 1); 
       printf(" The above is sent to the pipe_");
    } else {
                              // The parent
        int ab2  = fork();
        if (ab2  < 0) {
          fprintf(stderr, "fork #2 failed\n");
          exit(1);
        } else if (ab2 == 0) {
          // Child #2
          printf(" Child #2 ");
          close(ar[1]);      // Only read here
          dup2(ar[0], 0);    // Redirect stdin to pipe read

          /* 

          char buff[512];   // this crates a buffer
          read(STDIN_FILENO, buff, 512);  read from stdin
          printf("%s", buff);    //buffer is printed

        } else {
          // Initial parent process
          /* If we wait for rc1 then it could finish before rc2 is done,
           * giving us some strange behavior. */

          int wc = waitpid(ab2, NULL, 0);
          printf("goodbye");
        }
    }
    return 0;
}
