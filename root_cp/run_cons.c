#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


#include "config.h"


#include "semaphore.h"

/*
arguments
program name to execute
if init sem
amount of programs to run
sleep time
*/
int main(int argc, char **argv[])
{
    int i;
    pid_t child_pid;
    int pid;
    int pids[AMOUNT];
    char str_i[2];
    char* argument_list[] = {"./cons", "00", NULL};
    pid = (int)getpid();
    /*printf("%d\n", pid);*/

    if (atoi(argv[2])){
        sem_init(1);
    }

    for (i = 0; i < atoi(argv[3]); i++)
    {
        sprintf(str_i, "%d", i);
        argument_list[1] = str_i;
        child_pid = fork();
        if (child_pid == 0)
        {
            execvp(argv[1], argument_list);
        }
        else
        {
            pids[i] = (int)child_pid;
        }
    }

    printf("%d %d", pids[0], pids[1]);

    sleep(atoi(argv[4]));
    for (i = 0; i < atoi(argv[3]); i++)
    {
        kill(pids[i], 9);
    }
    return 0;
}