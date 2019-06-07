#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include "childwait.h"

int n = 0;

//SIGNAL HANDLER
void sig_usr(){
   pid_t pid;
   pid= wait(NULL);
   n--;
   printf("PARENT %7d: sleep(2)\n",getpid());
   printf("CHILD %8u: terminated (n=%d)\n",pid,n);
}

int main(int argc, char *argv[]){
   if(argc != 2) {
      puts("usage: ./demo_childwait <number of childprocess>");
      return EXIT_FAILURE;
   }
   signal(SIGCHLD, sig_usr);

   int argvInt = atoi(argv[1]);

   switch(argvInt){
      case 1 ... INT_MAX:
         childwait(argvInt);
         break;
      default: 
         fprintf(stderr, "...");
         exit(1);
         break;
   }

   if (n == 0)
      printf("PARENT %7d: terminated\n",getpid());

   return EXIT_SUCCESS;
}