#include <stdio.h>
#include <stdlib.h>

#include "process.h"
#include "queue.h"
#include "processmodel.h"

void print(pctx_t *ctx)
{
   puts("\nRunning Process:");
   if(ctx == NULL)
   {
      fputs("Invalid Context\n",stderr); 
      return;
   }

   if(ctx->running != NULL)
      p_print(ctx->running);
   else
      puts("No process is running");

   if(ctx->qready == NULL)
   {
      fputs("Invalid Queue",stderr); 
      return;
   }
   
   if(ctx->qblocked == NULL)
   {   
      fputs("Blocked Queue is empty",stdout); 
      return;
   }
   puts("\nReady Process/-es:");
   q_print(ctx->qready);
   puts("\nBlocked Process/-es:");

   q_print(ctx->qblocked);
}

void step(pctx_t *ctx)
{
   if(ctx == NULL) 
   {
      fputs("Invalid Context",stderr); 
      return;
   }
   
   if(ctx->qready == NULL) 
   {
      fputs("Invalid Queue",stderr);
      return;
   }
 
   if(ctx->running == NULL)
   {
      ctx->running = q_remove(ctx->qready);
      p_switch_state(ctx->running);
   }
   else
   {
      p_switch_state(ctx->running);         // Stopt den lfd. Prozess und fügt ihn in Queue
      q_add(ctx->qready, ctx->running);
      ctx->running = q_remove(ctx->qready);  // Lädt den nächsten Prozess
      p_switch_state(ctx->running);
   }
}
