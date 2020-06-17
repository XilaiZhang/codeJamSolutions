T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    steps=[]
    if N<=30:
        r=1
        k=1
        while N>0:
            steps.append([r,k])
            r+=1
            N-=1
    else:
        r=1
        k=1
        answer=0
        N-=30
        for i in range(30):
            if (N &(1<<i)):
                if k==1:
                    while k<r:
                        steps.append([r,k])
                        k+=1
                else:
                    while k>1:
                        steps.append([r,k])
                        k-=1
                steps.append([r,k])
                answer+=2**i
                r+=1
                if k!=1:
                    k+=1
                
            else:
                steps.append([r,k])
                answer+=1
                r+=1
                if k!=1:
                    k=k+1
        while answer<N+30:
            steps.append([r,k])
            answer+=1
            r+=1
            if k!=1:
                k+=1
    print "Case #"+str(tt)+":"
    for step in steps:
        print str(step[0])+" "+str(step[1])
    