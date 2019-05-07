N, M = map(int,input().split())

rel = [[101 for i in range(N)] for j in range(N)]
for i in range(N):
    rel[i][i]=0
#receive
for i in range(M):
    a, b = map(int,input().split())
    rel[a-1][b-1]=1
    rel[b-1][a-1]=1


def travle(start, end):
    for i in range(N):
        tmp = rel[end][i]
        if tmp != 101 and i != start:
            if rel[start][i] > tmp + rel[start][end]:
                rel[start][i] = tmp + rel[start][end]
flag = True
while(flag):
    flag= False
    for i in range(N):
        #101 still exist
        if 101 in rel[i]:
            flag=True
            for j in range(N):
                if i!=j and rel[i][j] != 101:
                    travle(i,j)
minist = sum(rel[0])
index = 0
for i in range(1,N):
    if minist>sum(rel[i]):
        minist=sum(rel[i])
        index = i
print(index+1)
