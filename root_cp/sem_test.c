#include <stdlib.h>
#include <stdio.h>
#include "semaphore.h"

int main(void){
    int status;
    /* printOne(); */
    printf("just begining: ");
    status = sem_status();
    printf("%d\n", status);
    
    printf("up: ");
    sem_up();
    status = sem_status();
    printf("%d\n", status);

    printf("down: ");
    sem_down();
    status = sem_status();
    printf("%d\n", status);
    
    return 0;
}