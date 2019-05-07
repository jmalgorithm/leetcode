while True:
    N = int(input())
    if N == 0 :
        break

    red = 0
    black = 0

    table = []

    for i in range(N):
        income = int(input())
        table.append([income, income])
        res = table[0][0]

        for j in range(i):
            table[j][1] += income
            if table[j][0] < table[j][1]:
                table[j][0] = table[j][1]
                if res < table[j][0]:
                    res= table[j][0]

    print(res)
