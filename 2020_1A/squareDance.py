T=int(raw_input())

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    deleted=[]
    neighbors=[[[-1,-1,-1,-1] for j in range(C)] for i in range(R)]
    grid=[]
    currentSum=0
    for i in range(R):
        line=[int(number) for number in raw_input().split()]
        grid.append(line)
    for i in range(R):
        for j in range(C):
            currentSum+=grid[i][j]
            amount=[]
            if i>0:
                neighbors[i][j][0]=i-1
                amount.append(grid[i-1][j])
            if i<R-1:
                neighbors[i][j][1]=i+1
                amount.append(grid[i+1][j])
            if j>0:
                neighbors[i][j][2]=j-1
                amount.append(grid[i][j-1])
            if j<C-1:
                neighbors[i][j][3]=j+1
                amount.append(grid[i][j+1])
            if amount and sum(amount)*1.0/len(amount)>grid[i][j]:
                deleted.append([i,j])
    result=currentSum
    
    while deleted:
        candidates=set()
        for x,y in deleted:
            currentSum-=grid[x][y]  #watch out for duplicate
            a,b,c,d=neighbors[x][y]
            if a>=0:
                neighbors[a][y][1]=b
                candidates.add((a,y))
            if b>=0:
                neighbors[b][y][0]=a
                candidates.add((b,y))
            if c>=0:
                neighbors[x][c][3]=d
                candidates.add((x,c))
            if d>=0:
                neighbors[x][d][2]=c
                candidates.add((x,d))
        result+=currentSum
        for x,y in deleted:
            candidates.discard((x,y))
        deleted=[]
        
        for i,j in candidates:
            a,b,c,d=neighbors[i][j]
            amount=[]
            if a>=0:
                amount.append(grid[a][j])
            if b>=0:
                amount.append(grid[b][j])
            if c>=0:
                amount.append(grid[i][c])
            if d>=0:
                amount.append(grid[i][d])
            if amount and sum(amount)*1.0/len(amount)>grid[i][j]:
                deleted.append([i,j])

    
    print "Case #"+str(tt)+": "+str(result)

    