N = int(input())

def findOne(list):
    try:
        res=list.index(1)
    except ValueError:
        res = len(list)

    return res
    
def wayFinder(a,b, way, house):
    if(house[a][b]==0):
        #cross
        if(house[a-1][b]==0 and house[a][b-1]==0):
            way[a][b][2] = sum(way[a-1][b-1])
        #verical
        if(a>0):
            if(house[a-1][b]==0):
                way[a][b][0]+=way[a-1][b][0]+way[a-1][b][2]
        #horizontal
        if(b>0):
            if(house[a][b-1]==0):
                way[a][b][1]+=way[a][b-1][1]+way[a][b-1][2]                



house = [[int(x) for x in input().split()]for y in range(N)]
way = [ [[0,0,0] for x in range(N) ]for y in range(N)]


#(a, b)[vertical][horizontal][cross]
#intialize
if(house[0][2]==0):
    way[0][1][1]=1

for i in range(N):
    for j in range(1,N):
        wayFinder(i,j,way,house)

print(sum(way[N-1][N-1]))
