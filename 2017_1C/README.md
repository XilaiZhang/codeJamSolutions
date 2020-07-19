ampleSyrup.cpp: standard 1d knapsack dp.

parentingPartnering.py: we first let each parent take care of their own intervals. Then, we try to close the gap between two intervals taken care by the same parent. We greedily close up the gaps (smaller gaps first, then larger gaps), as long as the total sum do not exceed 720. For those gaps between same parent intervals that we could not close, we need two switches. For gaps between different parent intervals, we always need exactly one switch.
