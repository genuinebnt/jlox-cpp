#!/usr/bin/env bash

if ! [ -d build/ ] 
then
    echo "Creating build folder" && mkdir build
fi

echo "Installing libraries with conan"

venv/bin/conan install . --output-folder=build --build=missing --profile conanprofile.toml