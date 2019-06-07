#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "process.h"
#include "queue.h"
#include "processmodel.h"

pctx_t *ctx0;

//SIGNAL HANDLER
void sig_usr(int sig_number){
   if(sig_number == SIGUSR1){
      if(ctx0->running == NULL)
         return;
      p_switch_state_block(ctx0->running);
      q_add(ctx0->qblocked, ctx0->running);
      ctx0->running = NULL;
      step(ctx0);
   }
   else if(sig_number == SIGUSR2){
      if(ctx0->qblocked->start == NULL)
         return;
      process_t *process_temp = q_remove(ctx0->qblocked);
      p_switch_state_block(process_temp);
      q_add(ctx0->qready, process_temp);
   }
}

int main() {
   uint32_t i;
   //create queue ready
   queue_t *qready = malloc(sizeof(queue_t));
   if(qready == NULL){
      fputs("Kein Speicherplatz vorhanden", stderr);
      return -1;
   }
   qready->start = NULL;
   qready->end = NULL;

   //create queue block
   queue_t *qblocked = malloc(sizeof(queue_t));
   if(qblocked == NULL){
      fputs("Kein Speicherplatz vorhanden", stderr);
      return -1;
   }
   qblocked->start = NULL;
   qblocked->end = NULL;

   //create processes
   process_t *processNumber[10];
   for (i=0; i<10; i++) {
      processNumber[i]=malloc(sizeof(process_t));
      if(processNumber[i]==NULL) {
         fputs("Kein Speicherplatz vorhanden", stderr);
         return -1;
      }
      if(i<1) {
         processNumber[i]->p_id=i;
         processNumber[i]->p_state=RUNNING;
      }
      else {
         processNumber[i]->p_id=i;
         processNumber[i]->p_state=READY;
         q_add(qready,processNumber[i]);
      }
   }

   ctx0 = malloc(sizeof(pctx_t));
   if(ctx0 == NULL){
      fputs("Kein Speicherplatz vorhanden", stderr);
      return -1;
   }
   ctx0->qready = qready;
   ctx0->qblocked = qblocked;
   ctx0->running = processNumber[0];
   signal(SIGUSR1, sig_usr);
   signal(SIGUSR2, sig_usr);

   while(1){
      printf("\033[H\033[J");
      printf("ProcessID: %u", getpid());
      printf("\n-----------------------------\n");
      print(ctx0);
      step(ctx0);
      sleep(1);
  }

   return 0;
}

