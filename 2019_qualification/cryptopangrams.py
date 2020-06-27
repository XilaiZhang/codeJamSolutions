T=int(raw_input())

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

for tt in range(1,T+1):
    N,L=raw_input().split()
    L=int(L)
    numbers=[int(t) for t in raw_input().split()]
    seen=set()
    vals=[]
    prev=[]
    prevG=None
    for i in range(1,L):
        a,b=numbers[i-1],numbers[i]
        if a==b:
            if prevG!=None:  #the case of last one
                comp=a/prevG
                vals.append(comp)
                seen.add(comp)
                prevG=comp
                if i==L-1:
                    vals.append(b/comp)
                    seen.add(b/comp)
                continue
            prev.append(numbers[i])
            if i==1:
                prev.append(numbers[i])
            continue
        g=gcd(a,b)
        if prev:
            stack=[]
            comp=a/g
            choice=[comp,g]
            index=0
            while prev:
                prev.pop()
                stack.append(choice[index])
                index=(index+1)%2
            while stack:
                s=stack.pop()
                vals.append(s)
                seen.add(s)
        if i==1:
            seen.add(a/g)
            vals.append(a/g)
        seen.add(g)
        vals.append(g)
        if i==L-1:
            seen.add(b/g)
            vals.append(b/g)
        prevG=g
    seen=list(seen)
    seen.sort()
    numRank={}
    for i in range(26):
        numRank[seen[i]]=i
    result=""
    for val in vals:
        result+=chr(ord('A')+numRank[val])
    print "Case #"+str(tt)+": "+result
