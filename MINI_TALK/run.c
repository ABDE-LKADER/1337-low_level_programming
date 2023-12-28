#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

void func()
{
    write(1, "You Can't Stop ME :) \n", 23);
}

void func2()
{
    write(1, "HHHHHHHHH DON'T TRY You Can't Stop ME :) \n", 23);
}

void segv()
{
    write(2, "Segmentation fault HHHHHHHHHHHHHHHHHHH !!!!!!! \n", 21);
}

int main()
{
    int i = 1;
    // int *i = NULL;
    // int *p = NULL;
    // signal(SIGINT, func);
    // signal(SIGTERM, func2);

    // *p = 54;
    int pid = fork();
    // kill(getpid(), 11);
    fork();
    while (++i<5)
    {
        if (pid == 0)
        {
            printf("\nCHILD: OK HERE WE GO : %d So What Is The First %d\n", pid, getpid());
            // sleep(1);
        }
        else
        {
            wait(NULL);
            printf("\nPARENT: OK HERE WE GO : %d So What Is The First %d\n", pid, getpid());
            // sleep(1);
        }
        sleep(1);
    }
}
