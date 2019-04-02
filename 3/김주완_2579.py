stair_num = int(input())
stair = []

for i in range(stair_num):
    stair.append(int(input()))

score = [[stair[0], 0, 0],
         [stair[0] + stair[1], stair[1], 0]]

for i in range(2, stair_num):
    tmp = []
    if score[i-1][0] > score[i-1][1]:
        if score[i-1][2] == 0:
            tmp.append(score[i-1][1] + stair[i])
        else:
            tmp.append(score[i-1][0] + stair[i])
    else:
        tmp.append(score[i-1][1] + stair[i])
    tmp.append(max(score[i-2][0], score[i-2][1]) + stair[i])
    if tmp[0] > tmp[1]:
        tmp.append(0)
    else:
        tmp.append(1)
    score.append(tmp)

print(max(score[stair_num-1][:2]))
print(score)
