#!/bin/bash

echo "Setup GUI test ^_^"

git clone --recursive https://github.com/faaxm/anyrpc.git
cd anyrpc && mkdir build && cd build || exit
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF -DBUILD_WITH_LOG4CPLUS=OFF -DANYRPC_LIB_BUILD_SHARED=OFF ..
sudo cmake --build . --target install
