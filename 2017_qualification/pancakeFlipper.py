
T=int(raw_input())

for tt in range(1,T+1):
    line,K=raw_input().split()
    K=int(K)
    L=len(line)
    event=[0 for x in range(L+1)]
    currentFlip=0

    flip=0
    for i in range(L):
        currentFlip+=event[i]
        if (line[i]=="-" and not (currentFlip & 1)) \
            or (line[i]=="+" and (currentFlip & 1)):
            if i+K-1>=L:
                flip="IMPOSSIBLE"
                break
            event[i+K]+=1
            flip+=1
            currentFlip+=1
    
    print "Case #"+str(tt)+": "+str(flip)
    




    
