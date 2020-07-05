import math
T=int(raw_input())

powers=[1]
for i in range(30):
    powers.append(powers[-1]*2)

for tt in range(1,T+1):
    D, line=raw_input().split()
    D=int(D)
    L=len(line)
    rstart=L-1
    while rstart>=0 and line[rstart]=="C":
        rstart-=1
    p=0
    attack=0
    for i in range(rstart+1):
        if line[i]=="C":
            p+=1
        else:
            attack+=powers[p]
    diff=attack-D
    if diff<=0:
        print "Case #"+str(tt)+": 0"
        continue
    moves=0
    waitList=0
    for i in range(rstart,-1,-1):
        if line[i]=="S":
            waitList+=1
        else:
            available=powers[p-1]*waitList
            if available<diff:
                moves+=waitList
                diff-=available
                p-=1
            else:
                moves+=int(math.ceil(diff*1.0/powers[p-1]))
                diff=0
                p-=1
                break
    if diff>0:
        print "Case #"+str(tt)+": IMPOSSIBLE"
    else:
        print "Case #"+str(tt)+": "+str(moves)
    






       
