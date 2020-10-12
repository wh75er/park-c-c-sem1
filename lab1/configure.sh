#!/bin/sh

# Конфигурационный файл для CI

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
