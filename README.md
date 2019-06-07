# C_RTS
Echtzeitsysteme

## How to use the files
### Übung03 - [ueb03](https://github.com/tradzieda/C_RTS/tree/master/ueb03)
| Übung           | makefile               | discreption                       | files
| --------------- | ---------------------- | --------------------------------- | -----
| **Übung3 - A1** | make demo_processmodel | Processmodel with blocking        | demo_processmodel.c
|                 |                        |                                   | demo_processmodel_signal.sh
|                 |                        |                                   | process.c / .h
|                 |                        |                                   | queue.c / .h
|                 |                        |                                   | processmodel.c / .h
| **Übung3 - A2** | make demo_signal       | Own Signal Programming            | demo_signal.c
|                 |                        |                                   | signal_mylibary.c / .h
|                 | make demo_signalOrig   | Programm, how works with signal.h | demo_signalOrig
| **Übung3 - A3** | make demo_childwait    | **"in Progress"**                 | demo_childwait.c
|                 |                        |                                   | childwait.c / .h

**make all** - create all exutable files\
**make clean** - remove al exutable + debug files and directory

--------
Die Übungen dienen allein zu Lehrzwecken und wurden von den jeweiligen Dozenten zur Verfügung gestellt.
