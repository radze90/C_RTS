#include <stdio.h>
#include <stdint.h>
#include "process.h"

void p_switch_state(process_t *p)
{
   if (p == NULL)
      return;
   switch (p->p_state)
   {
      case READY:       
         p->p_state = RUNNING; break;
      case RUNNING:
         p->p_state = READY; break;
      default:
         break;
   }
}

void p_switch_state_block(process_t *p)
{
   if (p == NULL)
      return;

   switch (p->p_state)
   {
      case RUNNING:
         p->p_state = BLOCKED; break;
      case BLOCKED:
         p->p_state = READY; break;
      default:
         break;
   }
}


void p_print(process_t *p)
{
   switch (p->p_state)
   {
      case READY:
         printf("PID: %3d, Process is ready!\n", p->p_id);   break;
      case RUNNING:
         printf("PID: %3d, Process is running!\n", p->p_id);  break;
      case BLOCKED:
         printf("PID: %3d, Process is blocked!\n", p->p_id);  break;
      default:
         printf("Invalid Processstate\n");   break;
   }
}
