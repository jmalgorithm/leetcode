test = int(input())
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]  # north, east, south, west

for C in range(1, test + 1):
    N = int(input())
    road = []
    for i in range(N):
        road.append(list(map(int, input())))

    shortest_cost = [[99999] * N for i in range(N)]
    shortest_cost[0][0] = 0
    shortest_cost[1][0] = road[1][0]
    shortest_cost[0][1] = road[0][1]
    non_visit = []
    for i in range(N):
        for j in range(N):
            non_visit += [[i, j]]
    non_visit.remove([0, 0])

    cur = [0, 0]

    for i in range(N*N-1):
        Q = []
        for dir in directions:
            adj = [cur[0] + dir[0], cur[1] + dir[1]]
            if (0 <= adj[0] < N) and (0 <= adj[1] < N):
                if shortest_cost[adj[0]][adj[1]] > shortest_cost[cur[0]][cur[1]] + road[adj[0]][adj[1]]:
                    shortest_cost[adj[0]][adj[1]] = shortest_cost[cur[0]][cur[1]] + road[adj[0]][adj[1]]
        min_dir = non_visit[0]
        for [i, j] in non_visit:
            if shortest_cost[i][j] < shortest_cost[min_dir[0]][min_dir[1]]:
                min_dir = [i, j]
        cur = min_dir
        non_visit.remove(min_dir)

    print("#" + str(C), shortest_cost[N-1][N-1])
