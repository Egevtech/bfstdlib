#!/usr/bin/env bash

cc -c runtime.c -o runtime.o
cc -c stdlib.c -o stdlib.o
ar rcs runtime.o stdlib.o stdlib.a
