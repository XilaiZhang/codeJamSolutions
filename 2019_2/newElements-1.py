T=int(raw_input())

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def solve(tt):
    result=0
    N=int(raw_input())
    C=[0 for x in range(N)]
    J=[0 for x in range(N)]
    lookup=set()
    for i in range(N):
        C[i],J[i]=[int(t) for t in raw_input().split()]
    for i in range(N):
        for j in range(i+1,N):
            a=C[i]-C[j]
            b=J[i]-J[j]
            if a*b>0:
                continue
            if a!=0 and b!=0:
                a=abs(a)
                b=abs(b)
                g=gcd(a,b)
                a/=g
                b/=g
                lookup.add((a,b))
    result=len(lookup)+1
    print "Case #"+str(tt)+": "+str(result)


for tt in range(1,T+1):
    solve(tt)
    
    






       
