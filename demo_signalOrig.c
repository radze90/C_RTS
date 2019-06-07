#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
   sigset_t set;
   
   // Entfernt alle Signale aus der Signalmenge set
   sigemptyset(&set);
   puts("\n######### sigemptyset #########");
   printf("SIGTERM:\t%d\n", sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", sigismember(&set, SIGUSR2));

   // Fügt der Signalmenge set alle Signale hinzu.
   sigfillset(&set);
   puts("\n######### sigfillset #########");
   printf("SIGTERM:\t%d\n", sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", sigismember(&set, SIGUSR2));

   // Entfernt alle Signale aus der Signalmenge set
   sigemptyset(&set);
   puts("\n######### sigemptyset #########");
   printf("SIGTERM:\t%d\n", sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", sigismember(&set, SIGUSR2));

   // Fügt das Signal signum der Menge set hinzu.
   sigaddset(&set , SIGTERM);
   puts("\n######### sigaddset #########");
   printf("SIGTERM:\t%d\n", sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", sigismember(&set, SIGUSR2));

   // Entfernt das Signal signum aus Menge set.
   sigdelset(&set, SIGTERM);
   puts("\n######### sigdelset #########");
   printf("SIGTERM:\t%d\n", sigismember(&set, SIGTERM));
   printf("SIGINT: \t%d\n", sigismember(&set, SIGINT));
   printf("SIGUSR1:\t%d\n", sigismember(&set, SIGUSR1));
   printf("SIGUSR2:\t%d\n", sigismember(&set, SIGUSR2));

   return EXIT_SUCCESS;
}