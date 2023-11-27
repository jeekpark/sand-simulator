#!/bin/bash

git clone https://github.com/jeekpark/sand-simulator.git

mkdir -p ./sand-simulator/sfml
tar -xzvf ./sand-simulator/SFML-2.6.1-macOS-clang-arm64.tar.gz -C ./sand-simulator/sfml
mv ./sand-simulator/sfml/SFML-2.6.1-macOS-clang-arm64 ./sand-simulator/sfml/2.6.1


make -C sand-simulator clangd
