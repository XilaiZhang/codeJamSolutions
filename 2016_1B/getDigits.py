from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    line=raw_input()
    myDict=Counter(line)
    num8=myDict['G']
    num6=myDict['X']
    num4=myDict['U']
    num2=myDict['W']
    num0=myDict['Z']
    
    myDict['F']-=num4
    num5=myDict['F']
    myDict['I']-=num8
    myDict['I']-=num5
    myDict['I']-=num6
    num9=myDict['I']
    myDict['V']-=num5
    num7=myDict['V']
    myDict['R']-=num0
    myDict['R']-=num4
    num3=myDict['R']
    myDict['O']-=num0
    myDict['O']-=num2
    myDict['O']-=num4
    num1=myDict['O']
    number=[0]*num0+[1]*num1+[2]*num2+[3]*num3+[4]*num4+[5]*num5+[6]*num6+[7]*num7+[8]*num8+[9]*num9
    number.sort()
    number=[str(t) for t in number]

    print "Case #"+str(tt)+": "+"".join(number)
      
