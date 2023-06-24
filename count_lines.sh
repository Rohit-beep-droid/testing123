#!/bin/bash

echo "Enter file name:"
read file
lines=$(wc -l < "$file")
echo "Total number of lines: $lines"
