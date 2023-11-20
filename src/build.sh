#!/bin/sh
g++ -c utils/libbcomputils.cpp -o utils/libbcomputils.o
ar rcs utils/libbcomputils.a utils/libbcomputils.o
g++ bcomp.cpp -o bcomp -L utils/ -l:libbcomputils.a
