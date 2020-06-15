T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N=int(raw_input())
    times=[]
    for i in range(N):
        interval=[int(t) for t in raw_input().split()]
        interval.append(i)
        times.append(interval)
    times.sort()
    C=0
    J=0

    result=[0 for x in range(N)]
    for i in range(len(times)):
        s,e,seq=times[i]
        if s>=C:
            result[seq]="C"
            C=e
        elif s>=J:
            result[seq]="J"
            J=e
        else:
            result="IMPOSSIBLE"
            break
    if result!="IMPOSSIBLE":
        result="".join(result)

    print "Case #"+str(tt)+": "+result
    
        


    
        

