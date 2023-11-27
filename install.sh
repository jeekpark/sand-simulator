#!/bin/bash

git clone https://github.com/jeekpark/sand-simulator.git

mkdir -p ./sand-simulator/sfml/2.6.1

tar -xzvf ./sand-simulator/SFML-2.6.1-macOS-clang-arm64.tar.gz -C ./sand-simulator/sfml/2.6.1

make -C sand-simulator clangd
