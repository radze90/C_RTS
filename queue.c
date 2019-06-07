#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "process.h"

// fügt den Prozess am Ende einer Warteschlange hinzu
void q_add(queue_t *queue, process_t *process)
{
   if (queue == NULL)
   {
      fputs("Invalid Queue", stderr);
      return;
   }

   if (process == NULL)
   {
      fputs("Invalid Process", stderr);
      return;
   }

   q_node_t *queue_new = malloc(sizeof(q_node_t));     // Speicher reservieren
   queue_new->next = NULL;
   queue_new->p = process;

   // falls kein Prozess in der Warteschlange vorhanden ist
   if (queue->start == NULL)
   {
      queue->start = queue_new;
      queue->end = queue_new;
   }
   else
   {
      queue->end->next = queue_new;
      queue->end = queue_new;
   }
}

// Löscht den Prozess
process_t *q_remove(queue_t *queue)
{
   if (queue == NULL)
   {
      fputs("Invalid Queue", stderr);
      return NULL;
   }

   if (queue->start == NULL)
      return NULL;

   q_node_t *queue_node;
   process_t *process;

   queue_node = queue->start;          // Warteschlangenknoten Zwischenspeichern
   process = queue->start->p;          // Proczess Zwischenspeichern
   queue->start = queue->start->next;

   free(queue_node);                   // alten Warteschlangenknoten freigeben
   return process;
}

void q_print(queue_t *queue)
{
   if(queue == NULL)
   {
      fputs("Invalid Queue", stderr);
      return;
   }

   if(queue->start == NULL)
            puts("Queue is empty");

   q_node_t *queue_node = queue->start;

   while(queue_node != NULL)
   {
      p_print(queue_node->p);          // Prozess ausgeben
      queue_node = queue_node->next;   // Nächste Prozess in der Warteschlange
   }
}
