import random
T=200
chars=["/","/","\\","\\","-","|","."] #2 2 1 1 4
#mcustomize your probabilities by modifying the chars array


print "200"
for tt in range(1,T+1):
    print "3 3"
    for i in range(3):
        line=""
        for j in range(3):
            num=random.randrange(9)
            if num>6:
                line+="."
            else:
                line+=chars[num]
        print line
    

    



    


