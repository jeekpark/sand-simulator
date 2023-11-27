#!/bin/bash

git clone https://github.com/jeekpark/sand-simulator.git

arch=$(uname -m)

mkdir -p ./sand-simulator/sfml
if [ "$arch" = "x86_64" ]; then
  tar -xzvf ./sand-simulator/SFML-2.6.1-macOS-clang-64-bit.tar.gz -C ./sand-simulator/sfml
  mv ./sand-simulator/sfml/SFML-2.6.1-macOS-clang-64-bit ./sand-simulator/sfml/2.6.1
elif [ "$arch" = "arm64" ]; then
  tar -xzvf ./sand-simulator/SFML-2.6.1-macOS-clang-arm64.tar.gz -C ./sand-simulator/sfml
  mv ./sand-simulator/sfml/SFML-2.6.1-macOS-clang-arm64 ./sand-simulator/sfml/2.6.1
else
  echo "Unsupported architecture: $arch"
fi

echo "Architecture: $arch"
make -C sand-simulator clangd

