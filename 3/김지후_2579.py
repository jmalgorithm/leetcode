N = int(input())

table1 = [0 for i in range(2)]
table2 = [0 for i in range(2)]

for i in range(N):
    score = int(input())
    if i > 1 :
        tmp = max(table1)
        table1 = table2
        table2 = [table1[1]+score, tmp+score]
        print(table2)
    else :
        if i == 0:
            table1 = [score, score]
            print(table1)
        else:
            table2 = [max(table1) + score, score]
            print(table2)

print(max(table2))
