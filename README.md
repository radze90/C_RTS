# C_RTS
Echtzeitsysteme

## How to use the files
### Übung03 - [ueb03](https://github.com/tradzieda/C_RTS/tree/master/ueb03)
**>A1**

| makefile               | discreption                       | files                          |
| ---------------------- | --------------------------------- | ------------------------------ |
| make demo_processmodel | Processmodel with blocking        | demo_processmodel.c            |
|                        | Simulator for SIGUSR1/2 via bash  | demo_processmodel_signal.sh    |
|                        |                                   | process.c / .h                 |
|                        |                                   | queue.c / .h                   |
|                        |                                   | processmodel.c / .h            |

**>A2**

| makefile               | discreption                       | files
| ---------------------- | --------------------------------- | -----
| make demo_signal       | Own Signal Programming            | demo_signal.c
|                        |                                   | signal_mylibary.c / .h
| make demo_signalOrig   | Programm, how works with signal.h | demo_signalOrig

**>A3**

| makefile               | discreption                       | files
| ---------------------- | --------------------------------- | -----
| make demo_childwait    | **"in Progress"**                 | demo_childwait.c
|                        |                                   | childwait.c / .h

**make all** - create all exutable files\
**make clean** - remove al exutable + debug files and directory

--------
Die Übungen dienen allein zu Lehrzwecken und wurden von den jeweiligen Dozenten zur Verfügung gestellt.
