T=int(raw_input())

for tt in range(1,T+1):
    N,J=[int(t) for t in raw_input().split()]
    print "Case #"+str(tt)+":"
    
    for base in range(J):
        number=["0" for x in range(N)]
        number[0]="1"
        number[1]="1"
        number[-1]="1"
        number[-2]="1"
        for pos in range((N-4)/2):
            if (base &(1<<pos)):
                number[-2*(pos+1)-1]="1"
                number[-2*(pos+1)-2]="1"
        result="".join(number)
        result+=" 3 2 5 2 7 2 9 2 11"
        print result



    
