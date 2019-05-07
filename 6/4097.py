'''
date: 2019-05-03

연종이는 창업했다. 오늘은 창업한지 N일이 되었고, 매일 매일 수익을 적어놓았다.

어느 날 연종이는 가장 많이 돈을 번 구간이 언제인지 궁금해졌다.

오늘이 창업한지 6일 되었고, 수익이 다음과 같다고 하자.

1일: -3
2일: 4
3일: 9
4일: -2
5일: -5
6일: 8
이때, 가장 많은 돈을 번 구간은 2~6까지이고 총 수입은 14이다.

'''

import sys

while True:
    N = int(sys.stdin.readline())
    if N == 0:
        break
    incomes = []
    trans = [0]
    max_idx = 0
    for i in range(N):
        incomes += [int(sys.stdin.readline())]
        if incomes[max_idx] < incomes[i]:
            max_idx = i
        if i > 0 and incomes[i] * incomes[i-1] < 0:
            trans += [i]
    if incomes[max_idx] < 0:
        print(incomes[max_idx])
        continue
    sums = []
    for i in range(len(trans)-1):
        sums += [sum(incomes[trans[i]:trans[i+1]])]
    sums += [sum(incomes[trans[-1]:N])]
    max_idx = sums.index(max(sums))
    i = max_idx
    dir = -1
    loss = 0
    profit = sums[max_idx]
    while True:
        i += dir
        if i < 0:
            dir = 1
            loss = 0
            i = max_idx + dir
        if i > len(sums) - 1:
            break
        if sums[i] >= 0:
            p = loss + sums[i]
            if p >= 0:
                profit += p
                loss = 0
            else:
                loss = p
        else:
            loss += sums[i]
    print(profit)