pascalWalk.py: the sum of all numbers in line i of the pascal triangle is 2**(i-1). We express our target in binary form, if there is a 1 in the i th bit from right, we take all numbers on the i th line, otherwise we take a 1 on the sides. We prevent overshoot by subtracting 30 from our target, and compensate later by taking the 1s on the sides. 

squareDance.py: the key observation is that only dancers having been eliminated in the last round will affect their neighbors in the current round. We can store the neighbors of each dancer in a 2d array and update this 2d array.
