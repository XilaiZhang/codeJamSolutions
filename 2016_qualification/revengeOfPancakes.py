T=int(raw_input())

for tt in range(1,T+1):
    line=raw_input()
    l=len(line)
    count=0
    for i in range(1,l):
        if line[i]!=line[i-1]:
            count+=1
    if line[-1]=="-":
        count+=1
    print "Case #"+str(tt)+": "+str(count)
