import heapq
T=int(raw_input())

for tt in range(1,T+1):
    B,M=[int(t) for t in raw_input().split()]
    grid=[["0" for y in range(B)] for x in range(B)]
    if M>(1<<(B-2)):
        print "Case #"+str(tt)+": IMPOSSIBLE"
        continue

    print "Case #"+str(tt)+": POSSIBLE"
    for i in range(2,B):
        for j in range(i,B):
            grid[i-1][j]="1"
    for i in range(61):
        if (M & (1<<i)) and B-i-2>0:
            grid[0][B-i-2]="1"
    if M==(1<<(B-2)):
        for j in range(1,B):
            grid[0][j]="1"
    for i in range(B):
        print "".join(grid[i])


   
      
