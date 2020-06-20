from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    U=raw_input()
    freq=Counter()
    seen=set()
    for t in range(10000):
        Q,R=raw_input().split()
        freq[R[0]]+=1
        for c in R:
            seen.add(c)
    r=[key for key in seen]
    r.sort(key=lambda x:-freq[x])
    result="".join(r)
    result=result[-1]+result[:-1]
    print "Case #"+str(tt)+": "+result

   


    