n, k = map(int, input().split())
coins = []

for i in range(n):
    coins.append(int(input()))

count = [0] * (k+1)
count[0] = 1
for i in coins:
    for j in range(i, k+1):
            count[j] += count[j-i]

print(count[k])
