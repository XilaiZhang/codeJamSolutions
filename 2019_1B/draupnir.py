import sys
T,W=[int(t) for t in raw_input().split()]

powers=[1]
for i in range(1,64):
    powers.append(powers[-1]*2)

for tt in range(1,T+1):
    print 200
    sys.stdout.flush()
    response=int(raw_input())
    r6Block=response%powers[40]
    r6=r6Block/powers[33]
    r5Block=response%powers[50]
    r5=(r5Block-r6Block)/powers[40]
    r4Block=response%powers[57]
    r4=(r4Block-r5Block)/powers[50]

    print 56
    sys.stdout.flush()
    response=int(raw_input())
    r4Block=r4*powers[14]+r5*powers[11]+r6*powers[9]
    r3Block=response%powers[28]
    r3=(r3Block-r4Block)/powers[18]
    r2Block=response%powers[35]
    r2=(r2Block-r3Block)/powers[28]
    r1=(response-r2Block)/powers[56]

    print str(r1)+" "+str(r2)+" "+str(r3)+" "+str(r4)+" "+str(r5)+" "+str(r6)
    sys.stdout.flush()
    r=raw_input()
    if r=="-1":
        break
