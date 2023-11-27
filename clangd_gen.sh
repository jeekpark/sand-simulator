#!/bin/bash

sfml_path="sfml/2.6.1/include"

if [ ! -d "$sfml_path" ]; then
    echo "SFML library should exists in $sfml_path"
    exit 1
fi

pwd=$(pwd)

# CompileFlags:
#  Add: [-I../sfml/2.6.1/include, -std=c++11]

echo "CompileFlags:" > .clangd
echo "  Add: [-I$pwd/$sfml_path, -std=c++11]" >> .clangd