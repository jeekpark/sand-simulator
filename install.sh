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

sfml_bundle_out=${sfml_bundle%.tar.gz}

tar -xzvf ./sand-simulator/lib/sfml/$sfml_bundle -C ./sand-simulator/lib/sfml
mv ./sand-simulator/lib/sfml/$sfml_bundle_out ./sand-simulator/lib/sfml/2.6.1
mv ./sand-simulator/lib/sfml/2.6.1/extlibs/freetype.framework ./sand-simulator/lib/sfml/2.6.1/Frameworks/freetype.framework

make -C sand-simulator clangd

