import heapq
T=int(raw_input())

class node(object):
    def __init__(self, offset, times, index):
        self.offset=offset
        self.times=times
        self.index=index

    def __lt__(self,other):
        return self.offset>=other.offset

for tt in range(1,T+1):
    N,L=[int(t) for t in raw_input().split()]
    languages=[int(t) for t in raw_input().split()]
    candidates=[[] for x in range(N)]
    currentSum=0
    numbers=[]
    result=0
    ref=(N+1)/2
    increment=100%N
    sentinel=N-increment
    for i in range(L):
        currentSum+=languages[i]
        whole=languages[i]*100/N
        fraction=languages[i]*100%N
        if fraction>=ref:
            result+=whole+1
        else:
            if increment==0:
                result+=whole
            else:
                candidates[i]=[whole,fraction,0]
                if fraction>=sentinel:
                    numbers.append(node(-N+fraction,0,i))
                else:
                    numbers.append(node(fraction,0,i))
    
    for i in range(L,N):
        candidates[i]=[0,0,0]
        numbers.append(node(0,0,i))

    heapq.heapify(numbers)
    remainder=N-currentSum
    while remainder>0:
        remainder-=1
        myNode=heapq.heappop(numbers)
        myNode.offset=myNode.offset+increment
        myNode.times+=1
        candidates[myNode.index][2]=myNode.times
        if myNode.offset<ref:
            if myNode.offset>=sentinel:
                myNode.offset=-N+myNode.offset
            heapq.heappush(numbers,myNode)

    for i in range(N):
        if candidates[i]:
            whole,fraction,times=candidates[i]
            raw=fraction+times*100
            whole+=raw/N
            raw=raw%N
            if raw>=ref:
                whole+=1
            result+=whole

    print "Case #"+str(tt)+": "+str(int(result))
    
