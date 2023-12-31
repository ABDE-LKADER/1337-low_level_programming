#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{   char array[16];
    int fd[2];

    pipe(fd);
    int id = fork();
    write (fd[1], "HELLO I AM HERE", sizeof(array));
    read(fd[0], array, sizeof(array));
    printf("%s\n", array);
    // sleep(1000);
    return (0); 
}
