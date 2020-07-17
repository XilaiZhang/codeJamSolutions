
T=int(raw_input())

def solve():
    N,P=[int(t) for t in raw_input().split()]
    recipe=[int(t) for t in raw_input().split()]
    intervals=[]
    flag=True
    for i in range(N):
        interval=[]
        for t in raw_input().split():
            x,y= (int(t)*10-1)/(11*recipe[i])+1, (int(t)*10)/(9*recipe[i])
            if x<=y:
                interval.append([x,y])

        interval.sort(key=lambda x:(x[1], x[0]))
        if not interval:
            flag=False
        intervals.append(interval)
    
    if not flag:
        return 0

    result=0
    candidates=[intervals[x][-1] for x in range(N)]
    while True:
        left=-1
        right=1000001
        flag=True
        maxPos=-1
        maxIndex=-1
        for i in range(N):
            x1,y1=candidates[i]
            if x1>maxPos:
                maxPos=x1
                maxIndex=i
            if x1>right or y1<left:
                flag=False
            left=max(left,x1)
            right=min(right,y1)
        if flag:
            result+=1
            for j in range(N):
                intervals[j].pop()
                if not intervals[j]:
                    return result
            for j in range(N):
                candidates[j]=intervals[j][-1]
        else:
            intervals[maxIndex].pop()
            if not intervals[maxIndex]:
                return result
            else:
                candidates[maxIndex]=intervals[maxIndex][-1]

for tt in range(1,T+1):
    r=solve()
    print "Case #"+str(tt)+": "+str(r)







    
