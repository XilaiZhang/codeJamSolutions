from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    N,C,M=[int(t) for t in raw_input().split()]
    BtoP=Counter()
    pCount=Counter()
    for i in range(M):
        P,B=[int(t) for t in raw_input().split()]
        BtoP[B]+=1
        pCount[P]+=1
    maxBound=0
    for key in BtoP:
        maxBound=max(maxBound,BtoP[key])
    
    empty=0
    for i in range(1,N+1):
        while pCount[i]-maxBound>empty:
            maxBound+=1
            empty+=i-1
        if pCount[i]>maxBound:
            empty-=pCount[i]-maxBound
        else:
            empty+=maxBound-pCount[i]

    z=0
    for i in range(1,N+1):
        if pCount[i]>maxBound:
            z+=pCount[i]-maxBound
    print "Case #"+str(tt)+": "+str(maxBound)+" "+str(z)

    



    


