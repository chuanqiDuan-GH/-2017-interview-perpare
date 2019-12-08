#!/bin/bash

script_abs=$(readlink -f "$0")
script_dir=$(dirname $script_abs)

#echo "$script_abs" "$script_dir"

cd $script_dir

rm -rf ../output/
mkdir ../output/
make clean
make

cd - > /dev/null 2>&1
