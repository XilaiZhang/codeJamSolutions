T=raw_input()
T=int(T)

for tt in range(1,T+1):
    line=raw_input()
    count=0
    result=""
    for i in range(len(line)):
        current=int(line[i])
        if current>count:
            result+="("*(current-count)
            result+=line[i]
            count=current
        elif current<count:
            result+=")"*(count-current)
            result+=line[i]
            count=current
        else:
            result+=line[i]
    result+=count*")"
    print "Case #"+str(tt)+": "+result

    
        

