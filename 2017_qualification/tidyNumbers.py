
T=int(raw_input())

for tt in range(1,T+1):
    number=raw_input()
    chars=[x for x in number]
    nineStart=-1
    for i in range(len(number)-1,0,-1):
        if chars[i]<chars[i-1]:
            chars[i-1]=chr(ord(chars[i-1])-1)
            nineStart=i
    if nineStart>=0:
        for i in range(nineStart,len(chars)):
            chars[i]="9"
    j=0
    while chars[j]=="0":
        j+=1
    result="".join(chars[j:])
    
    print "Case #"+str(tt)+": "+str(result)
    




    
