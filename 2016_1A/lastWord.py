from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    S=raw_input()
    result=S[0]
    for i in range(1,len(S)):
        if S[i]>=result[0]:
            result=S[i]+result
        else:
            result+=S[i]
    print "Case #"+str(tt)+": "+result
      
