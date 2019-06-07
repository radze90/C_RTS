#!/bin/bash

usage(){
    echo "usage: $0 <processID>" > /dev/stderr
    exit 1
}

if [ $# -ne 1 ]; then
    usage
fi

clear
i="3"
while [ $i -ne 0 ]; do
    echo "------------------------------------------------------------------"
    echo "  ProcessID: $1"
    echo "  Choose your Signal: SIGUSR1 -> (1), SIGUSR2 -> (2), exit -> (0)"
    echo
    read answer
    if [ $answer -eq 0 ]; then
        i="0"
    elif [ $answer -eq 1 ]; then
        echo "  --> kill -s SIGUSR1 $1"
        kill -s SIGUSR1 $1
    elif [ $answer -eq 2 ]; then
        echo "  --> kill -s SIGUSR2 $1"
        kill -s SIGUSR2 $1
    else
        echo "  -----> Choose 1, 2 or 0! <-----"
    fi
done