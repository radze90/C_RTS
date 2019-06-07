/* https://unix.stackexchange.com/questions/85364/how-can-i-check-what-signals-a-process-is-listening-to
** $cat /proc/1/status
** 0x00 .. 1800004ec (32bit)
** 0001 1000 0000 0000 0000 0000 0100 1110 1100
** 
*/

#include <stdio.h>
#include "signal_mylibary.h"

int my_sigemptyset(my_sigset_t *set){
   if(set == NULL)
      return -1;
   *set = 0;

   return 0;
}

int my_sigfillset(my_sigset_t *set){
   if(set == NULL)
      return -1;
   *set = 0xFFFFFFFF;
   
   return 0;
}

int my_sigaddset(my_sigset_t *set ,int signum){
   if(set == NULL)
      return -1;
   my_sigset_t add = 1 << (signum - 1);  // -1 da Signal ab 1 anfängt
   *set |= add;

   return 0;
}

int my_sigdelset(my_sigset_t *set, int signum){
   if(set == NULL)
      return -1;
   my_sigset_t delete = 1 << (signum - 1);  // -1 da Signal ab 1 anfängt
   delete = ~delete;
   *set &= delete;

   return 0;
}

int my_sigismember(const my_sigset_t *set,int signum){
   if(set == NULL)
      return -1;
   my_sigset_t check;
   check = *set >> (signum - 1); // -1 da Signal ab 1 anfängt

   return check & 1;
}

int my_printallsig(my_sigset_t *set){
   my_sigset_t check, i = 31;

   for(i = 31; i > 0; i--){
      check = (*set >> (i - 1)) & 1;
      printf("%d", check);
      if(i%4 == 1)
         printf(" ");
   }
   puts("");
   return 0;
}
