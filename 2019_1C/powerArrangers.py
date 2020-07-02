
from collections import Counter
import sys
T,F=[int(t) for t in raw_input().split()]
expected=[-1,23,5,1]

for tt in range(1,T+1):
    result=""
    words=[i for i in range(119)]
    
    for r in range(1,4):
        wordList=[[] for x in range(5)]
        for word in words:
            print str(word*5+r)
            sys.stdout.flush()
            response=raw_input()
            wordList[ord(response)-ord("A")].append(word)
        for j in range(5):
            if len(wordList[j])==expected[r]:
                result+=chr(ord("A")+j)
                words=wordList[j]
                break

    print str(words[0]*5+4)
    sys.stdout.flush()
    last=raw_input()
    for char in ["A","B","C","D","E"]:
        if char not in result and char!=last:
            result+=char
            break
    result+=last

    print result
    sys.stdout.flush()
    r=raw_input()
    if r=="N":
        break


    






       
