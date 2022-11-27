#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
   int i;
   pid_t child_pid;
   for(i = 0; i < 2; i++)
     child_pid = fork();
   if(child_pid == 0)
     execvp("./test", NULL);
   return 0;
}