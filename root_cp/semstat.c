#include <stdlib.h>
#include <stdio.h>
#include <lib.h>
#include <minix/type.h>
#include <unistd.h>
#include "semaphore.h"

int main(void){
    int ptr;
    ptr = sem_status();
    printf("first in q: %d ", ptr);
    printf("\n");
    return 0;
}