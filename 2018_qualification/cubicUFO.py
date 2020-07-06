import math
T=int(raw_input())

for tt in range(1,T+1):
    A=float(raw_input())
    t=math.pi/4-math.acos(A/math.sqrt(2))
    print "Case #"+str(tt)+":"
    print "%0.16f"%(0)+" "+"%0.16f"%(0)+" "+"%0.16f"%(0.5)
    print "%0.16f"%(-0.5*math.sin(t))+" "+"%0.16f"%(0.5*math.cos(t))+" "+"%0.16f"%(0)
    print "%0.16f"%(0.5*math.cos(t))+" "+"%0.16f"%(0.5*math.sin(t))+" "+"%0.16f"%(0)
    
