#!/bin/bash

echo "Type the sentence below:"
sentence="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed at ante vel ipsum gravida interdum quis sed nunc. In hac habitasse platea dictumst. Fusce eu lacus sit amet arcu gravida tempus. Phasellus euismod ligula sed urna facilisis ultrices. Nulla facilisi. Suspendisse potenti. Vestibulum auctor mauris vitae ligula sollicitudin tristique. Sed ac feugiat diam. Nunc consectetur sem ac elit tincidunt, ac bibendum ligula tristique. Integer finibus felis at tellus egestas bibendum. Nam lacinia velit nec massa porttitor faucibus. Pellentesque dictum mattis magna eget ultrices. Nullam luctus, sapien in convallis dictum, risus risus tempus tortor, nec ullamcorper mi sem ac elit."
echo "$sentence"
read input
accuracy=$(awk -v var1="$input" -v var2="$sentence" 'BEGIN{ print length(var1)/length(var2) * 100}')
echo "Accuracy: $accuracy"
