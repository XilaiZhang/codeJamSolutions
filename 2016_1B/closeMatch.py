result=1e18
n1=0
n2=0
T=int(raw_input())
def fill(num1,num2,startIndex):
    global result
    global n1
    global n2
    if num1[startIndex]<num2[startIndex]:
        num1=num1.replace("?","9")
        num2=num2.replace("?","0")
    elif num1[startIndex]>num2[startIndex]:
        num1=num1.replace("?","0")
        num2=num2.replace("?","9")
    answer=abs(int(num1[startIndex:])-int(num2[startIndex:]))
    if answer<result:
        result=answer
        n1=num1
        n2=num2


def dfs(num1,num2,L,startIndex): #the priorities could be huge problem
    if startIndex==L:
        fill(num1,num2,0)
        return
    if num1[startIndex]!="?" and num1[startIndex]==num2[startIndex]:
        dfs(num1,num2,L,startIndex+1)
    elif num1[startIndex]=="?" and num1[startIndex]==num2[startIndex]:
        dfs(num1[:startIndex]+"0"+num1[startIndex+1:],num2[:startIndex]+"0"+num2[startIndex+1:],L,startIndex+1)
        fill(num1[:startIndex]+"0"+num1[startIndex+1:],num2[:startIndex]+"1"+num2[startIndex+1:],startIndex)
        fill(num1[:startIndex]+"1"+num1[startIndex+1:],num2[:startIndex]+"0"+num2[startIndex+1:],startIndex)
    elif num1[startIndex]!="?" and num2[startIndex]=="?":
        if num1[startIndex]!="0":
            fill(num1,num2[:startIndex]+chr(ord(num1[startIndex])-1)+num2[startIndex+1:],startIndex)
        dfs(num1,num2[:startIndex]+num1[startIndex]+num2[startIndex+1:],L,startIndex+1)
        if num1[startIndex]!="9":
            fill(num1,num2[:startIndex]+chr(ord(num1[startIndex])+1)+num2[startIndex+1:],startIndex)
    elif num1[startIndex]=="?" and num2[startIndex]!="?":
        if num2[startIndex]!="0":
            fill(num1[:startIndex]+chr(ord(num2[startIndex])-1)+num1[startIndex+1:],num2,startIndex)
        dfs(num1[:startIndex]+num2[startIndex]+num1[startIndex+1:],num2,L,startIndex+1)
        if num2[startIndex]!="9":
            fill(num1[:startIndex]+chr(ord(num2[startIndex])+1)+num1[startIndex+1:],num2,startIndex)
    else: #diff number
        fill(num1,num2,startIndex)



for tt in range(1,T+1):
    n1=0
    n2=0
    result=1e18
    num1,num2=raw_input().split()
    L=len(num1)
    dfs(num1,num2,L,0)

    print "Case #"+str(tt)+": "+n1+" "+n2
      
