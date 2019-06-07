#ifndef PROCESS_H
#define PROCESS_H PROCESS.H

#include <stdint.h>

typedef enum {READY, RUNNING, BLOCKED} state;

typedef struct
{
    uint32_t p_id;      // ProcessID = PID
    state    p_state;   // ProcessStatus
} process_t;

void p_switch_state(process_t *p);  // Switcht den Status (RUNNING, READY)
void p_switch_state_block(process_t *p); // Switcht den Status inkl. Blocked
void p_print(process_t *p);         // Gibt den Process aus

#endif
