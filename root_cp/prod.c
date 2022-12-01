#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "semaphore.h"

int main(int argc, char **argv[])
{
    int mag_state;
    int succeeded_to_store;
    int prod_items;
    FILE *fptr;
    char name[17];

    

    sprintf(name, "files/prod%s.txt", argv[1]);
    printf("%s", name);
    while (1)
    {
        /*prepare */
        prod_items = (rand() % (PROD_UP-PROD_LOW+1)) + PROD_LOW;
        if ((fptr = fopen(name, "a")) == NULL)
            exit(1);
        fprintf(fptr, "wyprodukowano %d\n", prod_items);
        fclose(fptr);
            

        sleep(1);
        /*try to enter*/
        sem_down();
        printf("sem down\n");

        /*either succeeded or woken up by someone else -> go into CS*/
        /*check state*/
        if ((fptr = fopen("files/magazine.txt", "r")) == NULL)
            exit(1);
        fscanf(fptr, "%d", &mag_state);
        fclose(fptr);
        /*if possible put stuff*/
        if (CAPACITY - mag_state >= prod_items)
        {
            succeeded_to_store = 1;
            if ((fptr = fopen("files/magazine.txt", "w")) == NULL)
                exit(1);
            mag_state += prod_items;
            fprintf(fptr, "%d", mag_state);
            fclose(fptr);
            printf("wrote\n");
        }
        else{
            succeeded_to_store = 0;
        }

        /*quit and let in someone else*/
        sem_up();
        printf("sem up\n");
        /*log what has been done*/
        if ((fptr = fopen(name, "a")) == NULL)
            exit(1);
        if (succeeded_to_store){
            fprintf(fptr, "odlozono do magazynu");
        }
        else{
            fprintf(fptr, "za malo miejsca");
        }
        
    }

    return 0;
}