T=int(raw_input())

for tt in range(1,T+1):
    J,P,S,K=[int(t) for t in raw_input().split()]
    if K>=S:
        result=J*P*S
        print "Case #"+str(tt)+": "+str(result)
        for i in range(1,J+1):
            for j in range(1,P+1):
                for k in range(1,S+1):
                    print str(i)+" "+str(j)+" "+str(k)
        continue
    result=J*P*K
    print "Case #"+str(tt)+": "+str(result)
    for i in range(1,J+1):
        for j in range(1,P+1):
            for k in range(K):
                print str(i)+" "+str(j)+" "+str((i+j+k)%S+1)
    


   
      
