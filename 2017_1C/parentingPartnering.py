
T=int(raw_input())

for tt in range(1,T+1):
    Ac,Aj=[int(t) for t in raw_input().split()]
    myList=[]
    usedC=0
    usedJ=0
    for i in range(Ac):
        C,D=[int(t) for t in raw_input().split()]
        myList.append([C,D,0])
        usedC+=D-C
    for i in range(Aj):
        J,K=[int(t) for t in raw_input().split()]
        myList.append([J,K,1])
        usedJ+=K-J
    myList.sort(key=lambda x:x[0])

    expandC=[]
    expandJ=[]
    N=len(myList)
    for i in range(N-1):
        if myList[i][2]==myList[i+1][2]:
            if myList[i][2]:
                expandJ.append(myList[i+1][0]-myList[i][1])
            else:
                expandC.append(myList[i+1][0]-myList[i][1])
    if myList[0][2]==myList[-1][2]:
        if myList[0][2]:
            expandJ.append(myList[0][0]+1440-myList[-1][1])
        else:
            expandC.append(myList[0][0]+1440-myList[-1][1])

    expandC.sort(key=lambda x: -x)
    expandJ.sort(key=lambda x: -x)

    reduce=0
    while expandC:
        if usedC+expandC[-1]<=720:
            usedC+=expandC.pop()
            reduce+=1
        else:
            break
    N+=len(expandC)

    while expandJ:
        if usedJ+expandJ[-1]<=720:
            usedJ+=expandJ.pop()
            reduce+=1
        else:
            break
    N+=len(expandJ)




    print "Case #"+str(tt)+": "+str(N-reduce)



    


