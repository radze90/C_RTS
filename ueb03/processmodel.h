#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H PROCESSMODEL.H

typedef struct pctx
{
   queue_t     *qready;
   process_t   *running;
   queue_t     *qblocked;
} pctx_t;

void print(pctx_t *ctx);
void step(pctx_t *ctx);

#endif
