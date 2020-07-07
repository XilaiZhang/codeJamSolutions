waffleChopper.cpp: we can store the possible cut ranges as intervals and process them.

bitParty.cpp: Initially I thought it is a dp problem, but then realized that we can change this problem from optimization problem to decision problem by applying binary search. Note that we have M as an upper bound and 0 as a lower bound. 

edgyBaking.cpp: We will definitely take every rectangle before cutting any one of them. Then, as we cut any of them, our total sum of perimeter can only go up. For each rectangle, we get a minimum value and an upper bound for cutting it, and thus if we cut several rectangles, we will obtain a cumulative lower bound and a cumulative upper bound on perimeter. We would like to find out the maximum upperBound given each possible lower bound. Let dp\[i] be the maximum upperBound we can achieve when our lower bound is i. We gradually include each rectangle into consideration, and update our dp values. (update from right to left to preserve old values)
