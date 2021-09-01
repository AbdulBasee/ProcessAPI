#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define true 1
#define false 1
int main()
{
    int file = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    int rc = fork();

    if (rc == 0) // child process
    {
        write(file, "true", 4);
        printf("hi,  I am the  child  process\n");
        printf("hello hell o\n");
        close(file);
    }
    else if (rc > 0)
    {
        char buffer[4];
        buffer[4] = '\0';
        while (strcmp(buffer, "true\0") != 0)
        {
            // I am closing and opening file again so that our program can see updated content.
            close(file);
            file = open("file.txt", O_CREAT | O_RDWR, S_IRWXU);
            read(file, buffer, 4);
            usleep(10 * 1000); // sleep for 10 milli-seconds
        }

        printf("I am the great  parent process\n");
        printf("bye\n");
    }
    close(file);
    return 0;
}
