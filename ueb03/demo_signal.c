#include <signal.h>
#include "signal_mylibary.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
   my_sigset_t set;

   // clear screen
   printf("\033[H\033[J");

   // random bits
   set = 4324194;
   puts("1. #########  RANDOM BITS  #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   // Entfernt alle Signale aus der Signalmenge set
   my_sigemptyset(&set);
   puts("\n2. ######### my_sigemptyset #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   // Fügt der Signalmenge set alle Signale hinzu.
   my_sigfillset(&set);
   puts("\n3. ######### my_sigfillset #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   // Entfernt alle Signale aus der Signalmenge set
   my_sigemptyset(&set);
   puts("\n4. ######### my_sigemptyset #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   // Fügt das Signal my_signum der Menge set hinzu.
   my_sigaddset(&set , SIGTERM);
   puts("\n5. ######### my_sigaddset #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   // Entfernt das Signal my_signum aus Menge set.
   my_sigdelset(&set, SIGTERM);
   puts("\n6. ######### my_sigdelset #########");
   printf("SIGTERM:\t%d\n", my_sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", my_sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", my_sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", my_sigismember(&set, SIGUSR2));
   printf("binary: \t");   my_printallsig(&set);

   return EXIT_SUCCESS;
}