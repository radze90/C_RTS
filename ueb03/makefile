WARNFLAGS = -W -Wall -Wextra -Werror
OPTFLAGS = -O3 -std=c11
CFLAGS += $(WARNFLAGS) -ggdb3 -fsanitize=address

all: demo_processmodel demo_signal

demo_processmodel: process.c queue.c processmodel.c

demo_signal: signal_mylibary.c

demo_signalOrig:

demo_childwait: childwait.c

clean:
	$(RM) demo_processmodel demo_signal demo_signalOrig demo_childwait
