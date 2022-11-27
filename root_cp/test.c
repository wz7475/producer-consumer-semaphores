#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <minix/type.h>
#include <unistd.h>

int main(void) {
   message msg;
   int pid;
   pid = (int) getpid();
   printf("rozpoczecie procesu, PID=%d\n", pid);
   msg.m1_i1 = pid;
   _syscall(MM, PROCSUSPEND, &msg);
   printf("zakonczenie procesu, PID=%d\n", pid);
   return 0;
}