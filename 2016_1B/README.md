getDigits.py: we topologically associate capitalized letters with numerical numbers based on their dependencies ( similar to topological sort).

closeMatch.py; we can fill in the numbers as long as we set a first divergence point (the first digit that the two numbers start to differ). At each position, we create at most 2*\N extra operations, in total it is 2*\N*\N=O(N^2).
