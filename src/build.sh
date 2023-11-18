#!/bin/sh
g++ -c utils/utils.cpp -o utils/utils.o
ar rcs utils/utils.a utils/utils.o
g++ bcomp.cpp -o bcomp -L utils/ -l:utils.a
