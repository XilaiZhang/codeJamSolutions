T=int(raw_input())

for tt in range(1,T+1):
    C,D=[int(t) for t in raw_input().split()]
    numbers=[int(t) for t in raw_input().split()]
    T=[]
    R=[]
    for i in range(2,C+1):
        if numbers[i-2]>0:
            T.append([-numbers[i-2],i])
        elif numbers[i-2]<0:
            R.append([numbers[i-2],i])
    pairs=[]
    for i in range(D):
        x,y=[int(t) for t in raw_input().split()]
        pairs.append([x,y])

    T.sort()
    R.sort()

    lastT=0
    lastR=0
    N=1

    myDict={1:0}
    while R or T:
        if R and -R[-1][0]<=N:
            myR,seq=R.pop()
            myR=-myR
            if myR==lastR:
                myDict[seq]=lastT
            else:
                lastT=lastT+1
                lastR=myR
                myDict[seq]=lastT
        elif T:
            myT,seq=T.pop()
            myT=-myT
            if myT==lastT:
                myDict[seq]=lastT
            else:
                lastR+=1
                lastT=myT
                myDict[seq]=myT
        N+=1
    result="Case #"+str(tt)+":"

    for i in range(D):
        x,y=pairs[i]
        a,b=myDict[x],myDict[y]
        if b>a:
            a,b=b,a
        elif a==b:
            a=b+1
        result+=" "+str(a-b)
    print result


   
    