expogo.py: key observation is that only the first jump covers odd distance, all subsequent jumps cover even distance. We can therefore rebase our destination after each jump.

blindFoldedBullseye.py: We first divide the entire grid into squares with side length A. If the center of the circle falls in one of the squares, at least one of the 4 corners of the square returns a "HIT". In this way, we can find a point P with "HIT" in 25 tries. Suppose line x is a horizontal line that passes point P and intersect circle at points x1 and x2, and line y is a vertical line that passes point P and intersect circle at points y1 and y2. We can find x1,x2,y1,y2 by binary search. After that, we can the center of the circle.