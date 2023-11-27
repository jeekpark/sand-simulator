#!/bin/bash

git clone https://github.com/jeekpark/sand-simulator.git

compiler=$(cc --version)
arch=$(uname -m)

if [[ $compiler == *"gcc"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-linux-gcc-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-macOS-clang-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "arm64" ]; then 
  sfml_bundle="SFML-2.6.1-macOS-clang-arm64.tar.gz"
fi


tar -xzvf ./sand-simulator/sfml/$sfml_bundle -C ./sand-simulator/sfml
mv ./sand-simulator/sfml/$sfml_bundle ./sand-simulator/sfml/2.6.1



make -C sand-simulator clangd

