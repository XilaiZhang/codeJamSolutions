from collections import defaultdict,deque
from bisect import bisect_left
T=int(raw_input())

for tt in range(1,T+1):
    X,Y,M=raw_input().split()
    X=int(X)
    Y=int(Y)
    result=2001

    time=1
    s=X
    t=Y

    for i in range(len(M)):
        if M[i]=="N":
            t+=1
        elif M[i]=="S":
            t-=1
        elif M[i]=="W":
            s-=1
        else:
            s+=1
        cost=abs(s)+abs(t)
        if cost<=time:
            result=min(result,time)
        time+=1

    if result==2001:
        result="IMPOSSIBLE"
    print "Case #"+str(tt)+": "+str(result)


    