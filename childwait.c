#include "childwait.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define CHILD 0

extern int n;

void childwait(int childs){
   int i;
   
   for(i = 0; i < childs; i++){
      n++;
      switch(fork()){
         case -1: 
            exit(1); 
            break;
         case CHILD: 
            sleep(i);
            exit(1);
            break;
      }
      printf("Child\t%d: %s (n=%d)\n", getpid(),"started", n);
   }
   return;
}