import sys
T,B=[int(t) for t in raw_input().split()]

for tt in range(1,T+1):
    result=[0 for x in range(B+1)] #remove the 0th later
    left=1
    right=B

    samePair=-1
    diffPair=-1
    for r in range(5):
        print str(left)
        sys.stdout.flush()
        a=int(raw_input())
        print str(right)
        sys.stdout.flush()
        b=int(raw_input())
        if a==b:
            samePair=left
        else:
            diffPair=left
        result[left]=a
        result[right]=b
        left+=1
        right-=1


    
    while left<right:
        complement=False
        reverse=False
        if samePair>=0:
            print str(samePair)
            sys.stdout.flush()
            newVal=int(raw_input())
            if newVal!=result[samePair]:
                complement=True
                #sameVal=newVal # let me reconsider this: sameVal can be changed if reverse?
        else:
            print str(1)
            sys.stdout.flush()
            garbage=raw_input()
        if diffPair>=0:
            print str(diffPair)
            sys.stdout.flush()
            newDiff=int(raw_input())
            if newDiff!=result[diffPair]:
                #diffVal=newVal#diffVal would also change if flip happen
                if not complement:
                    reverse=True
            else:
                if complement:
                    reverse=True
        else:
            print str(1)
            sys.stdout.flush()
            garbage=raw_input()

        if complement:
            for i in range(1,left):
                result[i]= (1- result[i])
                result[B+1-i]= (1- result[B+1-i])

        if reverse:
            for i in range(1,left):
                tmp=result[i]
                result[i]=result[B+1-i]
                result[B+1-i]=tmp

        for r in range(4):
            print str(left)
            sys.stdout.flush()
            a=int(raw_input())
            print str(right)
            sys.stdout.flush()
            b=int(raw_input())
            if a==b:
                samePair=left
            else:
                diffPair=left
            result[left]=a
            result[right]=b
            left+=1
            right-=1
            if left>=right:
                break

    answer=""
    for j in range(1,B+1):
        answer+=str(result[j])

    print str(answer)
    sys.stdout.flush()
    feedback=raw_input()
    if feedback=="N":
        break
    