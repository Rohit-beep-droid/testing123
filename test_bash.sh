#!/bin/bash

echo "Hello, World!"
echo "Enter your name:"
read name
echo "Hola, $name!"
echo "Enter a number:"
read num
if((num > 0)); then
    echo "Positive number"
elif((num < 0)); then
    echo "Negative number"
else
    echo "Zero"

fi

echo "Counting sheeps now!"

for ((i=1; i<=num; i++)); do
    echo "$i sheep"

done
