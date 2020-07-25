import heapq
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    q=[]
    numbers=[int(t) for t in raw_input().split()]
    for i in range(N):
        heapq.heappush(q,[-numbers[i], chr(ord("A")+i)])
    N=sum(numbers)
    result=""
    while q:
        num,char=heapq.heappop(q)
        num=num+1
        if num!=0:
            heapq.heappush(q,[num,char])
        result+=" "+char
        N-=1
        if q:
            top=-q[0][0]
            #print "top is "+str(top)+" N is "+str(N)
            if top*2>N:
                n,c=heapq.heappop(q)
                n+=1
                if n!=0:
                    heapq.heappush(q,[n,c])
                result+=c
                N-=1


    print "Case #"+str(tt)+":"+result
      
