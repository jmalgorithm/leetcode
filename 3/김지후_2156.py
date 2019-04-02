N = int(input())

table1 = [0 for i in range(2)]
table2 = [0 for i in range(2)]
maximum = 0
zero =0

for i in range(N-1):
    score = int(input())
    if i > 2 :
        tmp = max(table1)
        table1 = table2
        table2 = [table1[1]+score, tmp+score]
    else :
        if i == 0:
            table1 = [score, score]
        elif i ==1:
            table2 = [table1[0] + score, score]
    if 0 == score :
        zero = i
        if table2[0] > table2[1]:
            table2[1] = table2[0]
    if i - zero ==
    print(table1, table2)

if N != 0:
    score = int(input())
    maximum = max(table2[0], table2[1]+score, table1[0]+score, table1[1]+score)
print(maximum)
