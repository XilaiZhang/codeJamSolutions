import random
T=int(raw_input())

def check(a,b,C):
    x1=a/C
    y1=a%C
    x2=b/C
    y2=b%C
    if x1==x2 or y1==y2 or x1-y1==x2-y2 or x1+y1==x2+y2:
        return False
    return True

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    N=R*C
    seq=[x for x in range(N)]

    possible=False
    for step in range(1000):
        for i in range(N-1):
            j=random.randrange(i,N)
            seq[i],seq[j]=seq[j],seq[i]

        index=0
        while index<N-1:
            found=False
            for j in range(index+1,N):
                if check(seq[index],seq[j],C):
                    seq[index+1],seq[j]=seq[j],seq[index+1]
                    found=True
                    index+=1
                    break
            if not found:
                break
        if index!=N-1:
            continue
        else:
            possible=True
            break

    if not possible:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
    else:
        print "Case #"+str(tt)+": "+"POSSIBLE"
        for i in range(N):
            print str(seq[i]/C+1)+" "+str(seq[i]%C+1)
