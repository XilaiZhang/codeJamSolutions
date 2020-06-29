from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    P,Q=[int(t) for t in raw_input().split()]
    points=[]
    xDict=defaultdict(lambda: [0,0])
    yDict=defaultdict(lambda: [0,0])
    for i in range(P):
        x,y,direction=raw_input().split()
        x,y=int(x),int(y)
        if direction=="W":
            xDict[x][0]+=1
        elif direction=="E":
            xDict[x][1]+=1
        elif direction=="S":
            yDict[y][0]+=1
        else:
            yDict[y][1]+=1

    pointsX=[[x,xDict[x][0],xDict[x][1]] for x in xDict]
    pointsX.sort()
    pointsX.insert(0,[-5,0,0]);
    pointsX.append([Q+5,0,0])
    
    L=len(pointsX) # L is now 2 more than toatl valid points
    for i in range(L-2,-1,-1):
        pointsX[i][1]+=pointsX[i+1][1]

    for i in range(1,L):
        pointsX[i][2]+=pointsX[i-1][2]

    rx=0
    valX=pointsX[1][1]

    for i in range(1,L-1):
        currentX=pointsX[i][0]
        if currentX!=Q:
            if currentX+1==pointsX[i+1][0]:
                newVal=pointsX[i+2][1]+pointsX[i][2]
            else:
                newVal=pointsX[i+1][1]+pointsX[i][2]
            if newVal>valX:
                valX=newVal
                rx=currentX+1

    pointsY=[[y,yDict[y][0],yDict[y][1]] for y in yDict]
    pointsY.sort()
    pointsY.insert(0,[-5,0,0]);
    pointsY.append([Q+5,0,0])

    L=len(pointsY) # L is now 2 more than toatl valid points
    for i in range(L-2,-1,-1):
        pointsY[i][1]+=pointsY[i+1][1]

    for i in range(1,L):
        pointsY[i][2]+=pointsY[i-1][2]

    ry=0
    valY=pointsY[1][1]

    for i in range(1,L-1):
        currentY=pointsY[i][0]
        if currentY!=Q:
            if currentY+1==pointsY[i+1][0]: #rethink later
                newVal=pointsY[i+2][1]+pointsY[i][2]
            else:
                newVal=pointsY[i+1][1]+pointsY[i][2]
            if newVal>valY:
                valY=newVal
                ry=currentY+1

    print "Case #"+str(tt)+": "+str(rx)+" "+str(ry)




