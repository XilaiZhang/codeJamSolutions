T=int(raw_input())

for tt in range(1,T+1):
    K,C,S=[int(t) for t in raw_input().split()]
    if S*C<K:
        print "Case #"+str(tt)+": IMPOSSIBLE"
        continue
    result="Case #"+str(tt)+":"

    for i in range(1,S+1):
        if (i-1)*C+1>K:
            break
        pos=[]
        for j in range(1,C+1):
            p=(C*(i-1)+j-1)%K+1
            pos.append(p)

        start=pos.pop()
        while pos:
            start=(start-1)*K+pos.pop()
        result+=" "+str(start)
    print result

    



    
