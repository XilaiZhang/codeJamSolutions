T=int(raw_input())

def solve(x,y):
    steps=""
    x1=[0,-1,0,1]
    y1=[1,0,-1,0]
    moves=["N","W","S","E"]
    s=0
    t=0
    while True:
        for i in range(4):
            if s+x1[i]==x and t+y1[i]==y:
                steps+=moves[i] #return
                return steps
        if (x+y)%2==0:
            steps="IMPOSSIBLE"
            return steps
        if y%2==1:
            poss=(y-1+x)/2
            if poss%2==1:
                y=(y-1)/2
                x/=2
                steps+="N"
            else:
                poss=(y+1+x)/2
                y=(y+1)/2
                x/=2
                steps+="S"
        else:
            poss=(x-1+y)/2
            if poss%2==1:
                x=(x-1)/2
                y/=2
                steps+="E"
            else:
                x=(x+1)/2
                y/=2
                steps+="W"

for tt in range(1,T+1):
    x,y=[int(t) for t in raw_input().split()]
    result=solve(x,y)
    
    print "Case #"+str(tt)+": "+result

    