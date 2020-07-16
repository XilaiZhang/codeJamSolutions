pancakeFlipper.py: Let us model each flip as an event. A single flip from pancake i to pancake i+K-1 is equivalent to, one flip on K pancakes from pancake i to pancake i+K-1 and 2 flips on every pancake after pancake i+K. Iterating from left to right, whenver we see a pancake is facing down and the equivalent flip count is even, or a pancake is facing up but flip count is odd, we do one flip. Runtime is O(N).

tidyNumbers.py: iterate from end to start. if number\[i-1] is greater than number\[i], we decrease number\[i-1] by 1 and make every number after number\[i] digit 9.
