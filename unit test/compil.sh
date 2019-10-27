#!/bin/bash

if [ -z $1 ]; then
../setup.sh
lib=""
for pparam in "$@"
do
    lib="$pparam $lib"
done
fi
gcc test.c $lib -lud_utils -lud_memory -lud_pointer -o executable
./executable