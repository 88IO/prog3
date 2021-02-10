#!/bin/sh
set -x
if [ ! -e ./enigma ]; then
    gcc ./enigma.c ./rotor.c ./keyboard.c -o enigma
fi
./enigma
