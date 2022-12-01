#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define AMOUNT 2

int main(void) {
   int i;
   pid_t child_pid;
   int pid;
   int pids[AMOUNT];
   pid = (int) getpid();
   printf("%d\n", pid);

   for(i = 0; i < AMOUNT; i++){
     child_pid = fork();
     if(child_pid == 0){
       execvp("./test", NULL); 
     }
     else{
      pids[i] = (int) child_pid;
     }
   }

   printf("%d %d", pids[0], pids[1]);
   
   sleep(2);
   for (i=0; i < AMOUNT; i++){
    kill(pids[i], 9);
   }
   return 0;
}