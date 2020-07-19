
T=int(raw_input())

for tt in range(1,T+1):
    N,R,O,Y,G,B,V=[int(x) for x in raw_input().split()]
    result="IMPOSSIBLE"
    colors=[R,Y,B,O,G,V]
    color=0
    for k in range(6):
        if colors[k]:
            color |= (1<<k)

    reqY,reqB,reqR=V+1, O+1, G+1 
    if color==34:
        if V==Y:
            print "Case #"+str(tt)+": "+"VY"*Y
        else:
            print "Case #"+str(tt)+": "+result
        continue
    elif color==17:
        if G==R:
            print "Case #"+str(tt)+": "+"GR"*G
        else:
            print "Case #"+str(tt)+": "+result
        continue
    elif color==12:
        if O==B:
            print "Case #"+str(tt)+": "+"OB"*B
        else:
            print "Case #"+str(tt)+": "+result
        continue

    vGroup=""
    if V:
        if reqY>Y:
            print "Case #"+str(tt)+": "+result
            continue
        else:
            vGroup="YV"*V+"Y"
            Y-=reqY
    yVals=['Y']*Y
    if vGroup:
        yVals.append(vGroup)

    gGroup=""
    if G:
        if reqR>R:
            print "Case #"+str(tt)+": "+result
            continue
        else:
            gGroup="RG"*G+"R"
            R-=reqR
    rVals=['R']*R
    if gGroup:
        rVals.append(gGroup)

    oGroup=""
    if O:
        if reqB>B:
            print "Case #"+str(tt)+": "+result
            continue
        else:
            oGroup="BO"*O+"B"
            B-=reqB
    bVals=['B']*B
    if oGroup:
        bVals.append(oGroup)

    N=len(rVals)+len(yVals)+len(bVals)
    if len(rVals)*2>N or len(yVals)*2>N or len(bVals)*2>N:
        print "Case #"+str(tt)+": "+result
        continue
    chars=[yVals,rVals,bVals]
    chars.sort(key=lambda x:len(x))
    A=[-1 for x in range(N)]
    seq=0
    count=0
    while count<N:
        if A[seq]!=-1:
            seq=(seq+1)%N
        if not chars[-1]:
            chars.pop()
        A[seq]=chars[-1].pop()
        seq=(seq+2)%N
        count+=1

    print "Case #"+str(tt)+": "+"".join(A)



    


