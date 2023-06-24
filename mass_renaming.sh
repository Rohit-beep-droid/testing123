#!/bin/bash

# renames only .txt files to .py files
for file in *.txt; do
    mv "$file" "${file%.txt}.py"
done
