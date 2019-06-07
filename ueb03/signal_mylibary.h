#ifndef SIGNAL_MYLIBARY_H
#define SIGNAL_MYLIBARY_H SIGNAL_MYLIBARY.H

typedef unsigned int my_sigset_t;

int my_sigemptyset(my_sigset_t *set);
int my_sigfillset(my_sigset_t *set);
int my_sigaddset(my_sigset_t *set, int sig_num);
int my_sigdelset(my_sigset_t *set, int sig_num);
int my_sigismember(const my_sigset_t *set, int sig_num);
int my_printallsig(my_sigset_t *set);

#endif