#!/bin/bash

echo "Setup google test ^_^"
git clone https://github.com/google/googletest
cd googletest || exit
cmake .
make
sudo make install