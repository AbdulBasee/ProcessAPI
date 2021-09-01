
#include <sys/types.h>
#include <sys/wait.h>


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define MSGSIZE 100

int main(){
   char *msg="Hello from one child1";
   char inbuf[MSGSIZE];
   int p[2],pid1,pid2;
  
   if(pipe(p)<0){   //creating pipe for communication
       exit(1);
    }
  
   pid1=fork();//creating first child process
  
   if(pid1 > 0){//parent process
       pid2= fork();//creating another child process
       if(pid2 > 0){  //parent process
          wait(NULL);
       }
       else if(pid2==0){//child2 process
           printf("Receiving message in child2\n");
           read(p[0],inbuf,MSGSIZE);
           printf("%s\n",inbuf);
       }
   }else if(pid1==0){//child1 process
       printf("Sendning message from child1\n");
       write(p[1],msg,strlen(msg));
   }else
       exit(1);
  
   return 0;
}


