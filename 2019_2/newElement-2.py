from fractions import Fraction
T=int(raw_input())

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def compare(x1,y1,x2,y2):
    p1=x1*y2
    p2=y1*x2
    if p1<p2:
        return -1
    elif p1>p2:
        return 1
    else:
        return 0

def solve(tt):
    result="IMPOSSIBLE"
    N=int(raw_input())
    C=[0 for x in range(N)]
    J=[0 for x in range(N)]
    x1=0
    y1=1
    x2=1000000005
    y2=1
    for i in range(N):
        C[i],J[i]=[int(t) for t in raw_input().split()]
    for i in range(1,N):
        a=C[i]-C[i-1]
        b=J[i]-J[i-1]
        if a==0:
            if b<0:
                print "Case #"+str(tt)+": IMPOSSIBLE"
                return
            else:
                continue
        elif b==0:
            if a<0:
                print "Case #"+str(tt)+": IMPOSSIBLE"
                return
            else:
                continue
        if a<0 and b<0:
            print "Case #"+str(tt)+": IMPOSSIBLE"
            return 
        if a>0 and b>0:
            continue
        if b>0 and a<0:
            a=abs(a)
            g=gcd(a,b)
            a/=g
            b/=g
            if compare(a,b,x1,y1)>=0:
                x1=a
                y1=b
                if compare(x1,y1,x2,y2)>=0:
                    print "Case #"+str(tt)+": IMPOSSIBLE"
                    return
        if b<0 and a>0:
            b=abs(b)
            g=gcd(a,b)
            a/=g
            b/=g
            if compare(a,b,x2,y2)<=0:
                x2=a
                y2=b
                if compare(x1,y1,x2,y2)>=0:
                    print "Case #"+str(tt)+": IMPOSSIBLE"
                    return
    
    low=1
    high=y1+y2
    x3=x1*y2+y1*x2
    y3=2*y1*y2
    g3=gcd(x3,y3)
    x3/=g3
    y3/=g3
    ref=Fraction(x3,y3)
    while low<high:
        mid=low+(high-low)/2
        number=ref.limit_denominator(mid)
        v1,v2=number.numerator, number.denominator
        v1=x1*v2/y1-1
        while compare(v1,v2,x1,y1)<=0:
            v1+=1
        if compare(v1,v2,x2,y2)<0:
            high=mid
        else:
            low=mid+1
    r2=low
    r1=x1*r2/y1-1
    while compare(r1,r2,x1,y1)<=0:
        r1+=1

    print "Case #"+str(tt)+": "+str(r2)+" "+str(r1)


for tt in range(1,T+1):
    solve(tt)
    
    






       
