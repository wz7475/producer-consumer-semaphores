#include <stdlib.h>
#include <stdio.h>

int main(void){
    // int tab[5] = {1,2,3,4,5};
    int tab[5];

    int *ptr = &t;
    /*int *ptr = &tab; - throws warnings*/

    printf("%d\n", *(ptr+22));
    printf("%d\n", *(ptr+2));
    printf("%d\n", *(ptr+1));
    printf("%d\n", *(ptr));

    return 0;
}