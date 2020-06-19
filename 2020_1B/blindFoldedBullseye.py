T,A,B=[int(t) for t in raw_input().split()]
bound=10**9
import sys

def bSearch(low,high,y):
    while low<high:
        mid=low+(high-low)/2
        print str(mid)+" "+str(y)
        sys.stdout.flush()
        response=raw_input()
        if response=="CENTER":
            return "C"
        elif response=="HIT":
            high=mid
        elif response=="MISS":
            low=mid+1
    return low

def ySearch(low,high,x):
    while low<high:
        mid=low+(high-low)/2
        print str(x)+" "+str(mid)
        sys.stdout.flush()
        response=raw_input()
        if response=="CENTER":
            return "C"
        elif response=="HIT":
            high=mid
        elif response=="MISS":
            low=mid+1
    return low

def bSearchRight(low,high,y):
    while low<high:
        mid=low+(high-low)/2
        print str(mid)+" "+str(y)
        sys.stdout.flush()
        response=raw_input()
        if response=="CENTER":
            return "C"
        elif response=="HIT":
            low=mid+1
        elif response=="MISS":
            high=mid
    return low

def ySearchRight(low,high,x):
    while low<high:
        mid=low+(high-low)/2
        print str(x)+" "+str(mid)
        sys.stdout.flush()
        response=raw_input()
        if response=="CENTER":
            return "C"
        elif response=="HIT":
            low=mid+1
        elif response=="MISS":
            high=mid
    return low

def solve():
    for tt in range(1,T+1):
        x=-1
        y=-1
        flag=-1
        for i in range(-bound,bound+1,A):
            for j in range(-bound,bound+1,A):
                print str(i)+" "+str(j)
                sys.stdout.flush()
                response=raw_input()
                if response=="CENTER":
                    flag=0
                    break
                elif response=="HIT":
                    x=i
                    y=j
                    flag=1
                    break
                elif response=="WRONG":
                    return
            if flag>=0:
                break
        if flag==0:
            continue
        #flag==1
        x1=-1
        x2=-1
        feedback=bSearch(-bound,x,y)
        if feedback=="C":
            continue
        x1=feedback
        feedback=bSearchRight(x,bound+1,y)
        if feedback=="C":
            continue
        x2=feedback-1

        y1=-1
        y2=-1
        feedback=ySearch(-bound,y,x)
        if feedback=="C":
            continue
        y1=feedback
        feedback=ySearchRight(y,bound+1,x)
        if feedback=="C":
            continue
        y2=feedback-1

        x3=(x1+x2)/2
        y3=(y1+y2)/2

        f=-1
        off=[0,1,-1,2,-2,3,-3,4,-4,5,-5]
        for i in range(12):
            for j in range(12):
                print str(x3+off[i])+" "+str(y3+off[i])
                sys.stdout.flush()
                r=raw_input()
                if r=="CENTER":
                    f=1
                    break
                elif r=="WRONG":
                    return
            if f>0:
                break


solve()


    