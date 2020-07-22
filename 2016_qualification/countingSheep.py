from collections import Counter
T=int(raw_input())

def solve():
    N=int(raw_input())
    digits=Counter()

    for i in range(1,10**2+1):
        number=N*i
        number=str(number)
        for c in number:
            digits[c]+=1
        if len(digits)==10:
            return number
    return "INSOMNIA"

for tt in range(1,T+1):
    result=solve()
    print "Case #"+str(tt)+": "+result

 