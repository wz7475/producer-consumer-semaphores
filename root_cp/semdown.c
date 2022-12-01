#include <stdlib.h>
#include <stdio.h>
#include <lib.h>
#include <minix/type.h>
#include <unistd.h>
#include "semaphore.h"

int main(void){
    int pid;
    pid = (int) getpid();
    printf("%d\n", pid);
    sem_down();
 
    return 0;
}