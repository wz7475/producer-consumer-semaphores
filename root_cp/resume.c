#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <minix/type.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   message msg;
   int pid;
   pid = atoi(argv[1]);
   msg.m1_i1 = pid;
   printf("wznawianie procesu, PID=%d\n", pid);
   _syscall(MM, PROCRESUME, &msg);
   return 0;
}