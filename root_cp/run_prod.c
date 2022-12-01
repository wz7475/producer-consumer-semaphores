#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


#include "config.h"


#include "semaphore.h"

int main(void)
{
    int i;
    pid_t child_pid;
    int pid;
    int pids[AMOUNT];
    char str_i[2];
    char* argument_list[] = {"./prod", "00", NULL};
    pid = (int)getpid();
    printf("%d\n", pid);

    sem_init(1);

    for (i = 0; i < AMOUNT; i++)
    {
        sprintf(str_i, "%d", i);
        argument_list[1] = str_i;
        child_pid = fork();
        if (child_pid == 0)
        {
            execvp("./prod", argument_list);
        }
        else
        {
            pids[i] = (int)child_pid;
        }
    }

    printf("%d %d", pids[0], pids[1]);

    sleep(4);
    for (i = 0; i < AMOUNT; i++)
    {
        kill(pids[i], 9);
    }
    return 0;
}