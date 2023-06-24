#!/bin/bash

quotes=("Live life like there is no tomorrow." "Love is the remedy to everything." "Eat. Sleep. Code." "Always strive for a positive mindset." "Treat people how you would like to be treated." "Cannot teach old dog new tricks." "You live, you learn." "Take one baby step at a time." "Tomorrow will always be better than today." "Family over everything." "Read a book." "The best way to predict the future is to create it." "Life is your greatest teacher." "The only way to do great work is to love what you do." "You are loved." "Life is either a daring adventure or nothing at all." "Be curious." "Be responsible." "Be daring.")

random=$((RANDOM % ${#quotes[@]}))
echo "Quote of the day: ${quotes[random]}"
