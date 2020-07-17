
T=int(raw_input())

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    grid=[["?" for y in range(C)] for x in range(R)]
    for i in range(R):
        line=raw_input()
        char=-1
        for j in range(C):
            if line[j]!="?":
                char=line[j]
                grid[i][j]=char
                k=j-1
                while k>=0 and grid[i][k]=="?":
                    grid[i][k]=char
                    k-=1
            else:
                if char!=-1:
                    grid[i][j]=char
   
    line=-1
    for i in range(R):
        if grid[i][0]!="?":
            line=i
            k=i-1
            while k>=0 and grid[k][0]=="?":
                grid[k]=grid[i][:]
                k-=1
        else:
            if line!=-1:
                grid[i]=grid[line][:]

    
    print "Case #"+str(tt)+":"
    for i in range(R):
        print "".join(grid[i])
    




    
