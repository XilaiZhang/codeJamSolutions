T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    even=[]
    odd=[]
    numbers=raw_input().split()
    for i in range(N):
        if i%2==0:
            even.append(int(numbers[i]))
        else:
            odd.append(int(numbers[i]))
    even.sort()
    odd.sort()

    p1=0
    p2=0
    prev=-1
    result="OK"
    for i in range(N):
        current=None
        if i%2==0:
            current=even[p1]
            p1+=1
        else:
            current=odd[p2]
            p2+=1
        if current<prev:
            result=str(i-1)
            break
        prev=current

    
    print "Case #"+str(tt)+": "+result
    






       
