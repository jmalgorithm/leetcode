N = int(input())

# 0 = R, 1 = G, 2 = B
RGBcosts = []
for i in range(N):
    RGBcosts.append(list(map(int, input().split())))

cost = [RGBcosts[0]]

for i in range(1, N):
    colors = [min(cost[i-1][1], cost[i-1][2]) + RGBcosts[i][0],
              min(cost[i-1][0], cost[i-1][2]) + RGBcosts[i][1],
              min(cost[i-1][0], cost[i-1][1]) + RGBcosts[i][2]]
    cost.append(colors)

print(min(cost[N - 1]))
