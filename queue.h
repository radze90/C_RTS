#ifndef QUEUE_H
#define QUEUE_H QUEUE.H

#include "process.h"

typedef struct q_node
{
    struct q_node *next;
    process_t *p;
} q_node_t;            // Warteschlangeknoten

typedef struct
{
    q_node_t *start;
    q_node_t *end;
} queue_t;              // Warteschlange

void q_add(queue_t *q, process_t *p);
process_t *q_remove(queue_t *q);
void q_print(queue_t *q);

#endif
