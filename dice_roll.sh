#!/bin/bash

echo "Rolling a dice..."

dice=$((1 + RANDOM % 6))
echo "You've rolled a $dice!"
