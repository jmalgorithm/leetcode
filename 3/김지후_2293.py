N, K = map(int,input().split())
value = []
table = [0 for j in range(K+1)]
for i in range(N):
    value.append(int(input()))
table[0]=1
for i in range(N):
    for j in range(value[i], K+1):
        table[j] += table[j-value[i]]

print(table[K])
