#include <stdlib.h>
#include <stdio.h>
#include <lib.h>
#include <minix/type.h>
#include <unistd.h>
#include "semaphore.h"

int main(void){
    int stat;
    stat = sem_status();
    printf("%d\n", stat);
    return 0;
}