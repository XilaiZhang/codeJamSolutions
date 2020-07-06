import sys
T=int(raw_input())

def solve():
    grid=[[0 for y in range(69)] for x in range(4)]
    for y in range(1,68):
        for x in range(1,4):
            while not grid[x][y]:
                print str(2)+" "+str(min(66,y+1))
                sys.stdout.flush()
                r1,r2=[int(t) for t in raw_input().split()]
                if r1==0 and r2==0:
                    return
                grid[r1][r2]=1

for tt in range(1,T+1):
    A=raw_input()
    solve()
    





       
