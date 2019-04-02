import math
def length(a, b):
    return math.sqrt((a[0]-b[0])**2+(a[1]-b[1])**2)

def findMin(start, table):
    min=0
    index=0
    for i in range(start+1,len(table)):
        tmp=length(table[start],table[i])
        if(i == start+1):
            min = tmp
            index = i
        elif(tmp<min):
            min = tmp
            index = i
    return min, index

res = []
T = int(input())
for z in range(T):
    N = int(input())
    sum = 0
    table = []
    for i in range(N):
        a, b = map(int,input().split())
        table.append([a,b])

    startpoint = table[0]
    start = 0
    #갈때
    while True:
        if(start == len(table)-1):
            break
        a, b = findMin(start,table)
        sum+=a
        table.pop(start)
        start=b-1

    table.insert(0,startpoint)

    #올대
    for i in range(len(table)-1,0,-1):
        sum+=length(table[i],table[i-1])

    res.append(sum)

for i in range(len(res)):
    print(res[i])

