from collections import defaultdict,Counter
T=int(raw_input())

numbers=defaultdict()
answer=defaultdict(lambda:"IMPOSSIBLE")

def helper(val,depth,n):
    if depth==n:
        return val
    s1=None
    s2=None
    if val=="P":
        s1=helper("P",depth+1,n)
        s2=helper("R",depth+1,n)
    elif val=="S":
        s1=helper("P",depth+1,n)
        s2=helper("S",depth+1,n)
    else:
        s1=helper("R",depth+1,n)
        s2=helper("S",depth+1,n)
    if s1>s2:
        return s2+s1
    return s1+s2


for n in range(1,13):
    total=(1<<(n+1))-1
    nodes=["" for x in range(1<<(n+1))]
    for char in ["P","S","R"]:
        line=helper(char,0,n)
        checker=Counter(line)
        numbers[(n,char)]=(checker["R"],checker["P"],checker["S"])
        answer[(n,char)]=line


for tt in range(1,T+1):
    N,R,P,S=[int(t) for t in raw_input().split()]
    flag=False
    result="Z"
    for char in ["R","S","P"]:
        if numbers[(N,char)]==(R,P,S):
            result=min(result,answer[(N,char)])
            flag=True
    if flag:
        print "Case #"+str(tt)+": "+result
    else:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
        
    


   
      
