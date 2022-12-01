#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "semaphore.h"

int main(int argc, char **argv[])
{
    int mag_state;
    int prod_items;
    FILE *fptr;
    char name[12];

    sprintf(name, "prod%s.txt", argv[1]);
    printf("%s", name);
    while (1)
    {
        /*prepare */
        prod_items = (rand() + PROD_LOW) % PROD_UP;

        sleep(1);
        /*try to enter*/
        sem_down();
        printf("sem down\n");

        /*either succeeded or woken up by someone else -> go into CS*/
        /*check state*/
        if ((fptr = fopen("magazine.txt", "r")) == NULL)
            exit(1);
        fscanf(fptr, "%d", &mag_state);
        fclose(fptr);
        /*if possible put stuff*/
        if (CAPACITY - mag_state >= prod_items)
        {
            if ((fptr = fopen("magazine.txt", "w")) == NULL)
                exit(1);
            mag_state += prod_items;
            fprintf(fptr, "%d", mag_state);
            fclose(fptr);
            printf("wrote\n");
        }

        /*quit and let in someone else*/
        sem_up();
        printf("sem up\n");
        /*log what has been done*/
    }

    return 0;
}