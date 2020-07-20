
T=int(raw_input())

for tt in range(1,T+1):
    N,P=[int(t) for t in raw_input().split()]
    numbers=[int(t) for t in raw_input().split()]

    mods=[0,0,0,0]
    for num in numbers:
        mods[num%P]+=1

    result=mods[0]
    
    if P==2:
        if mods[1]:
            result+=(mods[1]-1)/2+1

    elif P==3:
        comm = min(mods[1], mods[2])
        result+=comm
        remainder= max(mods[1],mods[2])-comm
        if remainder:
            result+=(remainder-1)/3+1

    elif P==4:
        result+=mods[2]/2
        comm= min(mods[1],mods[3])
        result+=comm
        remainder= max(mods[1],mods[3])-comm
        if mods[2]%2==1:
            if remainder>1:
                remainder-=2
                result+=1
                if remainder:
                    result+=(remainder-1)/4+1
            else:
                result+=1
        else:
            if remainder:
                result+=(remainder-1)/4+1
    
    print "Case #"+str(tt)+": "+str(result)

    



    


