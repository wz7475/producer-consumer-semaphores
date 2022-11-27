#include<errno.h> /*errno*/
#include<lib.h> /*syscall*/
#include<minix/type.h> /*message*/
#include<stdlib.h> /*atoi*/
#include<stdio.h>

int getprocnr(int proc_id)
{
    message my_message;
    my_message.m1_i1 = proc_id; /*set proccess number in message*/
    return _syscall(MM, 78, &my_message);
}

/* test function */
int main(int argc, char *argv[])
{
    int proc_nr;
    int offset;
    int range = 10;
    /*expected one argument - pid*/
    if (argc != 2)
        printf("Expected one argument - pid!\n");
    else
    {
        int pid = atoi(argv[1]);
        for (offset = range; offset >= 0; --offset)
        {
            proc_nr = getprocnr(pid - offset);
            if (proc_nr != -1)
                printf("pid: %d - %d\n", pid - offset, proc_nr);
            else
                printf("pid: %d - error: %d\n", 
                pid - offset, errno);
        }
    }
    return 0;
}

