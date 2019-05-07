'''
date: 2019-05-04

N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
'''
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]   # east, south, west, north
N, M = map(int, input().split())
board = []
for i in range(N):
    board += [list(map(int, input()))]

# dp = [[-1] * N for i in range(M)]
# for i in range(N):
#     for j in range(M):
#         if i == 0 and j == 0:
#             dp[i][j][0] = 1
#             continue
#         if i == 0:
#             if board[i][j] == 0:
#                 dp[i][j] = [dp[i][j-1][0] + 1, dp[i][j-1][1]]
#             else:
#                 if dp[i][j-1][1] == -1:
#                     dp[i][j] = [-1, dp[i][j-1][1]]
#                 else:
#                     dp[i][j] = [dp[i][j-1][0] + 1, -1]
#             continue
#         if j == 0:
#             if board[i][j] == 0:
#                 dp[i][j] = [dp[i-1][j][0] + 1, dp[i-1][j][1]]
#             else:
#                 if dp[i-1][j][1] == -1:
#                     dp[i][j] = [-1, dp[i-1][j][1]]
#                 else:
#                     dp[i][j] = [dp[i-1][j][0] + 1, -1]
#             continue
#         min_idx = [i-1, j] if dp[i-1][j][0] < dp[i][j-1][0] else [i, j-1]
#         if board[i][j] == 0:
#             dp[i][j] = [dp[min_idx[0]][min_idx[1]][0] + 1, dp[min_idx[0]][min_idx[1]][1]]

# def find_path(i, j, brick, path, pre_dir):
#     if i == N-1 and j == M-1:
#         return len(path)
#     elif i == N or j == M:
#         return 1000000
#     elif i < 0 or j < 0:
#         return 1000000
#     else:
#         if board[i][j] == 1 and brick == False:
#             return 1000000
#         if board[i][j] == 1 and brick == True:
#             min_path = 1000000
#             for dir in directions:
#                 if dir != pre_dir:
#                     next = [i+dir[0], j+dir[1]]
#                     if next not in path:
#                         p = find_path(next[0], next[1], False, path+[next], [-dir[0], -dir[1]])
#                         if p < min_path:
#                             min_path = p
#             return min_path
#         if board[i][j] == 0:
#             min_path = 1000000
#             for dir in directions:
#                 if dir != pre_dir:
#                     next = [i+dir[0], j+dir[1]]
#                     if next not in path:
#                         p = find_path(next[0], next[1], brick, path+[next], [-dir[0], -dir[1]])
#                         if p < min_path:
#                             min_path = p
#             return min_path
# result = find_path(0, 0, True, [[0, 0]], [0, 0])
# if result == 1000000:
#     print(-1)
# else:
#     print(result)

# import time
# start = time.time()
# walls = [[0, 0]]
# for i in range(N):
#     for j in range(M):
#         if board[i][j] == 1:
#             zero_adj_right = False
#             zero_adj_left  = False
#             for dir in directions[0:2]:
#                 adj = [i+dir[0], j+dir[1]]
#                 if adj[0] < 0 or adj[1] < 0 or adj[0] >= N or adj[1] >= M:
#                     continue
#                 if board[adj[0]][adj[1]] == 0:
#                     zero_adj_right = True
#                     break
#             for dir in directions[2:4]:
#                 adj = [i + dir[0], j + dir[1]]
#                 if adj[0] < 0 or adj[1] < 0 or adj[0] >= N or adj[1] >= M:
#                     continue
#                 if board[adj[0]][adj[1]] == 0:
#                     zero_adj_left = True
#                     break
#             if zero_adj_right and zero_adj_left:
#                 walls += [[i, j]]
#
# short = 1000001
# for wall in walls:
#     board[wall[0]][wall[1]] = 0
#     visit = [[False]*M for i in range(N)]
#     dis = [[1000000]*M for i in range(N)]
#     dis[0][0] = 1
#
#     for i in range(N):
#         for j in range(M):
#             if board[i][j] == 1:
#                 visit[i][j] = True
#     while True:
#         m = 1000000
#         k = [-1, -1]
#
#         for i in range(N):
#             for j in range(M):
#                 if not visit[i][j] and m > dis[i][j]:
#                     m = dis[i][j]
#                     k = [i, j]
#         if m == 1000000:
#             break
#
#         visit[k[0]][k[1]] = True
#         if visit[N-1][M-1]:
#             print(visit)
#             break
#
#         for dir in directions:
#             adj = [k[0]+dir[0], k[1]+dir[1]]
#             if adj[0] < 0 or adj[1] < 0 or adj[0] >= N or adj[1] >= M:
#                 continue
#             if visit[adj[0]][adj[1]]: continue
#             via = dis[k[0]][k[1]] + 1
#             if dis[adj[0]][adj[1]] > via:
#                 dis[adj[0]][adj[1]] = via
#     if wall != [0, 0]:
#         board[wall[0]][wall[1]] = 1
#     if short > dis[N-1][M-1]:
#         short = dis[N-1][M-1]
# print("{} seconds".format(time.time()-start))
# if short == 1000000:
#     print(-1)
# else:
#     print(short)

import collections

dist = [[[0, 0] for i in range(M)] for i in range(N)]

def bfs():
    deq = collections.deque([(0, 0, 0)])
    dist[0][0][0] = 1
    while deq:
        x, y, crash = deq.popleft()
        if x == N-1 and y == M-1:
            return dist[x][y][crash]
        for dir in directions:
            nx, ny = x + dir[0], y + dir[1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if dist[nx][ny][crash]: # 0은 False랑 같다
                continue
            if board[nx][ny] == 0:
                dist[nx][ny][crash] = dist[x][y][crash] + 1
                deq.append((nx, ny, crash))
            if board[nx][ny] == 1 and crash == 0:
                dist[nx][ny][1] = dist[x][y][crash] + 1
                deq.append((nx, ny, 1))
    return -1

print(bfs())
