import sys
T=int(raw_input())

for tt in range(1,T+1):
    N,B,F=[int(t) for t in raw_input().split()]
    M=[["0" for j in range(N)] for i in range(5)]
    seq=0
    for i in range(N):
        for j in range(5):
            if (seq & (1<<j)):
                M[j][i]="1"
        seq=(seq+1)%32

    rMatrix=[]
    for r in range(5): 
        guess="".join(M[r])
        print guess
        sys.stdout.flush()
        response=raw_input()
        rMatrix.append(response)

    broke=[]
    prevNumber=33
    block=0
    for i in range(N-B):
        number=0
        for j in range(5):
            if rMatrix[j][i]=="1":
                number |= (1<<j)
        if i==0:
            for k in range(number):
                broke.append(k)
            prevNumber=number
            continue

        if number<prevNumber:
            for k in range(prevNumber+1,32):
                broke.append(block*32+k)
            block+=1
            for k in range(number):
                broke.append(block*32+k)
        elif number>prevNumber:
            for k in range(prevNumber+1,number):
                broke.append(block*32+k)
        prevNumber=number

    for k in range(block*32+prevNumber+1,N):
        broke.append(k)    

    broke=[str(b) for b in broke]
    print " ".join(broke)
    sys.stdout.flush()
    some=raw_input()
    if some=="-1":
        break

