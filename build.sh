#!/usr/bin/env bash

rm -rf runtime.o stdlib.o

cc -static -c runtime.c -o runtime.o
cc -static -c stdlib.c -o stdlib.o

ar rcs stdlib.a runtime.o stdlib.o
