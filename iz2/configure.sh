#!/bin/bash

# Конфигурационный файл для CI

TYPE=Debug
OPTIONS=-DUSE_PARALLEL=OFF

if [[ -z $1 ]]; then
  echo "Enter 0 to use naive implementation or 1 to use parallel. Exiting..."
  exit 1
fi

if [[ $1 -eq 1 ]]; then
  OPTIONS=-DUSE_PARALLEL=ON
fi

if [[ -n $2 ]]; then
  echo "Overriding TYPE=$TYPE with $2..."
  TYPE=$2
fi

echo "Configured TYPE=$TYPE and OPTIONS=$OPTIONS"

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=$TYPE $OPTIONS ..

exit 0
