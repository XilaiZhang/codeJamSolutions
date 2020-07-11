T=int(raw_input())

for tt in range(1,T+1):
    C=int(raw_input())
    B=[int(t) for t in raw_input().split()]
    result="IMPOSSIBLE"
    if B[0]==0 or B[-1]==0:
        print "Case #"+str(tt)+": "+result
        continue
    dist=[0 for x in range(C)]
    i=0
    j=0
    while j<C:
        while B[j]!=0:
            dist[i]=j
            i+=1
            B[j]-=1
        j+=1

    maxDist=0
    for i in range(C):
        maxDist=max(maxDist,abs(dist[i]-i))
    R=maxDist+1

    result=[['.' for y in range(C)] for r in range(R)]
    for i in range(C):
        s,t=0,i
        if dist[i]>i:
            diff=dist[i]-i
            while diff>0:
                result[s][t]="\\"
                s+=1
                t+=1
                diff-=1
        elif dist[i]<i:
            diff=i-dist[i]
            while diff>0:
                result[s][t]="/"
                s+=1
                t-=1
                diff-=1
    print "Case #"+str(tt)+": "+str(R)
    for i in range(R):
        print "".join(result[i])




    
