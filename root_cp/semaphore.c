#include <stdlib.h>
#include <stdio.h>
#include <lib.h> /*syscall*/
#include <minix/type.h> /*message*/
#include <unistd.h> /*getpid*/

void printOne()
{
    printf("1\n");
}

/*ready*/
int sem_status()
{
    int sem_status;
    message msg;
    sem_status = _syscall(MM, 80, &msg);
    return sem_status;
}

int sem_down()
{
    message msg;
    int pid;
    int result;
    pid = (int) getpid();
    msg.m1_i1 = pid;
    result = _syscall(MM, 81, &msg);
    return 0;
}

/*ready*/
int sem_up()
{
    message msg;
    int result;
    result = _syscall(MM, 81, &msg);
    return 0;
}

int sem_init(int value)
{
    message msg;
    int result;
    msg.m1_i1 = value;
    result = _syscall(MM, 81, &msg);
    return 0;
}