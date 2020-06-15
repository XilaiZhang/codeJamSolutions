T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N=int(raw_input())
    r=0
    c=0
    trace=0
    grid=[]
    for i in range(N):
        line=[int(t) for t in raw_input().split()]
        trace+=line[i]
        seen=set(line)
        if len(seen)!=N:
            r+=1
        grid.append(line)
    for j in range(N):
        seen=set()
        for i in range(N):
            seen.add(grid[i][j])
        if len(seen)!=N:
            c+=1
    print "Case #"+str(tt)+": "+str(trace)+" "+str(r)+" "+str(c)

    
        

