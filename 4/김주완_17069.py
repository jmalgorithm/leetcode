import sys

N = int(sys.stdin.readline())
board = []
for i in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

dp  = [[0] * N for i in range(N)]   # 대각선
dpN = [[0] * N for i in range(N)]   # 가로
dpD = [[0] * N for i in range(N)]   # 세로

dpN[0][1] = 1

for i in range(N):
    for j in range(N):
        if i == 0 and j == 0:
            continue
        if board[i][j] == 1:
            continue

        if j+1 < N and board[i][j+1] == 0:
            dpN[i][j+1] = dpN[i][j] + dp[i][j]
        if i+1 < N and board[i+1][j] == 0:
            dpD[i+1][j] = dpD[i][j] + dp[i][j]
        if i+1 < N and j+1< N and board[i+1][j+1] == 0 and board[i+1][j] == 0 and board[i][j+1] == 0:
            dp[i+1][j+1] = dp[i][j] + dpN[i][j] + dpD[i][j]

print(dp[N-1][N-1] + dpD[N-1][N-1] + dpN[N-1][N-1])
