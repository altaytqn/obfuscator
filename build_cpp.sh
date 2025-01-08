#!/usr/bin/env bash

echo "Compiling 5 C++ files..."
g++ -std=c++17 cpp_main.cpp cpp_utility.cpp cpp_engine.cpp cpp_core.cpp cpp_extra.cpp -o cpp_complex_app

if [ $? -eq 0 ]; then
  echo "Compilation successful. Running app..."
  ./cpp_complex_app
else
  echo "Compilation failed."
fi
