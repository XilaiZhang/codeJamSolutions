newElements-1.py: Let the ratio between the two element be k. The order between some pairs are irrelevant of k, others are related to k. The math reveals that each k in a specific range maps to a specifc ordering.

newElements-2.py: We have the lower bound and upper bound as fractions. The fractions.Fraction.limit_denominator(K) on the midpoint of the range allows us to find the most possible candidate that could be within the range, with a denominator at most K. We can then perform a binary search and find out the minimum possible denominator.
