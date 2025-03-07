#!/bin/zsh

g++ main.cpp -o executable

if [ -f "./executable" ]; then
    ./executable
    rm ./executable
else
    echo "!!! executable not found."
fi
