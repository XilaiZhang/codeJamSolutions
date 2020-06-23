incrementalPancake.cpp: When calculating the bounds, we make sure that long long do not overflow. Also, at each stage, we ensure that L or R always have more than value E if we decide to subtract E from either of them. Key observation is the two stacks decrease alternatively as we remove pancakes from them.

securityUpdate.py: An assignment of Time or ranks will lead to an assignment of latency. We can come up with a sorted list of computers by ranks, and another sorted list of computers by time. We merge the two lists together to create a complete sorted  list of rank or T. 

wormholeOne.cpp: Initially I thought it was dfs but then I realized that the wormholes are bidirectional and the ball must go into the "first" hole in the direction. After making the key observation that we only care about holes on the same line (with the same slope and offset), I come up with an union & find approach that solves the problem. 
