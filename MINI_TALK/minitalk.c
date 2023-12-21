#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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
    write(2, "Segmentation fault \n", 21);
}

int main()
{
    int i = 1;
    // int *p = NULL;
    signal(SIGINT, func);
    signal(SIGTERM, func2);
    signal(SIGSEGV, segv);
    
    // *p = 54;
    int pid = fork();
    // fork();
    while (i)
    {
        if (pid == 0)
            printf("CHILD: OK HERE WE GO : %d So What Is Teh First %d\n", getpid(), pid);
        else
            printf("PARENT: OK HERE WE GO : %d So What Is Teh First %d\n", getpid(), pid);
        sleep(1);
    }
}
