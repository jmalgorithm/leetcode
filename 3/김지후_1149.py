H = int(input())
case = []
price = []

for j in range(H):
    # Keep going
    if j != 0:
        price = list(map(int, input().split()))
        min1i = case.index(min(case))
        min1 = case.pop(min1i)
        min2 = min(case)
        case.insert(min1i,min1)

        for i in range(3):
            if (i != min1i):
                price[i] += min1
            else:
                price[i] += min2
        case = price


    # First begining
    else:
        price = list(map(int, input().split()))
        case = price

print(min(case))
