import sys
T,N,M=[int(t) for t in raw_input().split()]

for tt in range(1,T+1):
    numbers=[18,17,13,11,7,5,3]
    remainders=[]
    for r in range(7):
        query=[str(numbers[r])]*18
        print " ".join(query)
        sys.stdout.flush()
        response=[int(t) for t in raw_input().split()]
        remainder=sum(response)%numbers[r]
        remainders.append(remainder)
    currentBlock=1
    currentVal=remainders[0]
    if not currentVal:
        currentVal+=numbers[0]
    for i in range(6):
        currentBlock*=numbers[i]
        targetVal=numbers[i+1]
        targetMod=remainders[i+1]
        while currentVal%targetVal!=targetMod:
            currentVal=currentVal+currentBlock

    print currentVal
    sys.stdout.flush()
    f=raw_input()
    if f=="-1":
        break
    
