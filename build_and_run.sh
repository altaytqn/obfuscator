#!/usr/bin/env bash

echo "Building C components..."
gcc c/c_main.c c/c_obf_python.c c/c_obf_cpp.c c/c_obf_csharp.c c/c_utils.c -o mega_c_obf

echo "Running Ruby main to demonstrate Ruby-based obfuscation..."
ruby ruby/r_main.rb

echo "Running compiled C main to demonstrate C-based obfuscation..."
./mega_c_obf
