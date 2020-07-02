
T=int(raw_input())
letter=["R","S","P"]

for tt in range(1,T+1):
    A=int(raw_input())
    words=set()
    for i in range(A):
        word=raw_input()
        words.add(word)

    result=""
    done=False
    for l in range(1,501):
        j=l-1
        exist=[[],[],[]]
        if not words:
            break
        for word in words:
            c=word[j%(len(word))]
            if c=="R":
                exist[0].append(word)
            elif c=="S":
                exist[1].append(word)
            else:
                exist[2].append(word)
            
        if exist[0] and exist[1] and exist[2]:
            done=True
            result="IMPOSSIBLE"
            break
        
        caseTwo=False
        for k in range(3):
            if exist[k] and exist[(k+1)%3]:
                caseTwo=True 
                result+=letter[k]
                for loser in exist[(k+1)%3]:
                    words.discard(loser) #find a way to continue
                break

        if caseTwo:
            continue

        for k in range(3):
            if exist[k]:
                done=True
                result+=letter[(k+2)%3]
                words=None
                break
        if done:
            break
    if words:
        result="IMPOSSIBLE"
    print "Case #"+str(tt)+": "+result






       
