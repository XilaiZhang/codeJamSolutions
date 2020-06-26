T=int(raw_input())

for tt in range(1,T+1):
    N=raw_input()
    seq=raw_input()
    result=""
    for c in seq:
        if c=="S":
            result+="E"
        else:
            result+="S"
    
    print "Case #"+str(tt)+": "+result
