from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    myDict=Counter()
    for i in range(2*N-1):
        numbers=[int(t) for t in raw_input().split()]
        for num in numbers:
            myDict[num]+=1
    result=[key for key in myDict if myDict[key]%2==1]
    result.sort()
    result=[str(t) for t in result]

    print "Case #"+str(tt)+": "+" ".join(result)
      
