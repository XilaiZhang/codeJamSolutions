T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    currentPrefix=""
    currentPostfix=""
    flag=True
    middle=""
    i=1
    while i<=N:
        word=raw_input()
        words=word.split("*")
        p=words[0]
        s=words[-1]
        
        for j in range(min(len(currentPrefix),len(p))):
            if currentPrefix[j]!=p[j]:
                flag=False
                break
        if len(p)>len(currentPrefix):
            currentPrefix+=p[len(currentPrefix):]

        for j in range(1,min(len(s),len(currentPostfix))+1):
            if currentPostfix[-j]!=s[-j]:
                flag=False
                break
        if len(s)>len(currentPostfix):
            currentPostfix=s[0:(len(s)-len(currentPostfix))]+currentPostfix
        if not flag:
            break

        if len(words)>2:
            other="".join(words[1:-1])
            middle+=other
        i+=1

    i+=1
    while i<=N:
        some=raw_input()
        i+=1
    result="*"
    if flag:
        result=currentPrefix+middle+currentPostfix
    print "Case #"+str(tt)+": "+result
    