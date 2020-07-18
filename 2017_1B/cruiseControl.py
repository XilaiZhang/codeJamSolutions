
T=int(raw_input())

for tt in range(1,T+1):
    D,N=[int(x) for x in raw_input().split()]
    maxTime=-1
    for i in range(N):
        K,S=[int(x) for x in raw_input().split()]
        maxTime=max(maxTime, (D-K)*1.0/S)

    print "Case #"+str(tt)+": %.6f" % (D*1.0/maxTime)







    
