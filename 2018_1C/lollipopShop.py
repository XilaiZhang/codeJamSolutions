import sys, random
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    number=[0 for k in range(N)]
    sold=set()
    for i in range(N):
        line=[int(t) for t in raw_input().split()]
        D=line[0]
        for j in range(1,D+1):
            number[line[j]]+=1
        minList=[]
        minVal=N+1
        for j in range(1,D+1):
            possible=line[j]
            if possible in sold:
                continue
            if number[possible]<minVal:
                minVal=number[possible]
                minList=[possible]
            elif number[possible]==minVal:
                minList.append(possible)
        if not minList:
            print "-1"
            sys.stdout.flush()
            continue
        index=random.randrange(len(minList))
        print minList[index]
        sys.stdout.flush()
        sold.add(minList[index])



    
