from collections import defaultdict,Counter
import sys
T=int(raw_input())

for tt in range(1,T+1):
    N,B,F=[int(t) for t in raw_input().split()]
    broke=set()
    valid=defaultdict()
    points=[0,N]

    for r in range(1,F+1): 
        guess=""
        newpoints=[0]
        for i in range(1,len(points)):
            low,high=points[i-1],points[i]
            mid=(high+low)/2
            newpoints.append(mid)
            newpoints.append(high)
            guess+="0"*(mid-low)
            guess+="1"*(high-mid)
        print guess
        sys.stdout.flush()
        response=raw_input()
        index=0

        for i in range(1,len(points)):
            low,high=points[i-1],points[i]
            mid=(high+low)/2
            validRange=None
            if r==1:
                validRange=len(response)
            else:
                validRange=valid[(low,high)]
            vResponse=response[index:index+validRange]
            index+=validRange

            ref=Counter(vResponse)
            left=ref["0"]
            right=ref["1"]
            
            if left==0: #everything is broke, we can reach this granularity
                for j in range(low,mid):
                    broke.add(j)
            if right==0:
                for j in range(mid,high):
                    broke.add(j)
            valid[(low,mid)]=left
            valid[(mid,high)]=right
        points=newpoints

    broke=list(broke)
    broke.sort()
    broke=[str(b) for b in broke]

    print " ".join(broke)
    sys.stdout.flush()
    some=raw_input()
    if some=="-1":
        break

