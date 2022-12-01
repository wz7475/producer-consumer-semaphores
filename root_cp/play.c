#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv[])
{

    char name[12];

    sprintf(name, "prod%s.txt", argv[1]);
    printf("%s", name);
    return 0;
}