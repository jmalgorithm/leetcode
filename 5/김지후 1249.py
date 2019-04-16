T=int(input())
 
for t in range(T):
    N = int(input())
    cost = [[-1 for j in range(N)]for k in range(N)]
    road = []
    #read road
    for k in range(N):
        tmp = input()
        road.append([int(tmp[i:i+1]) for i in range(len(tmp))])
    cost[0][0]=road[0][0]
    #half
    for i in range(1,N):
        for b in range(0,i+1):
            a = i-b
            if(a>0 and b>0):
                cost[a][b]=road[a][b]+min(cost[a-1][b],cost[a][b-1])
            elif(a==0):
                cost[a][b]=road[a][b]+cost[a][b-1]
            elif(b==0):
                cost[a][b]=road[a][b]+cost[a-1][b]
    #half
    s=0
    for i in range(N,2*N+1):
        s+=1
        for b in range(s,i-s+1):
            a = i-b
            cost[a][b]=road[a][b]+min(cost[a-1][b],cost[a][b-1])
    print("#%d %d"%(t+1,cost[N-1][N-1]))
