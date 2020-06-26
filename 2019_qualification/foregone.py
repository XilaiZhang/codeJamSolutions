T=int(raw_input())

for tt in range(1,T+1):
    N=raw_input()
    a=""
    b=""
    for i in range(len(N)):
        if N[i]!="4":
            a+=N[i]
            if b:
                b+="0"
        else:
            a+="1"
            b+="3"

    
    print "Case #"+str(tt)+": "+a+" "+b
