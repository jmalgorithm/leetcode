num = int(input())
amount = [0]

for i in range(num):
    amount.append(int(input()))

drink = [0] * (num + 1)

for i in range(1, num+1):
    if i > 3:
        break
    else:
        if i == 0:
            drink[i] = amount[i]
        else:
            drink[i] = amount[i-1] + amount[i]

# for i in range(2, num):
#     if drink[i-1][0] == max(drink[i-1]):
#         if drink[i-1][3] == 0:
#             drink[i][0] = max(drink[i-1][1:3]) + amount[i]
#         else:
#             drink[i][0] = drink[i-1][0] + amount[i]
#     else:
#         drink[i][0] = drink[i-1][drink[i-1][3]] + amount[i]
#     drink[i][1] = drink[i-2][drink[i-2][3]] + amount[i]
#     drink[i][2] = drink[i-1][drink[i-1][3]]
#     drink[i][3] = drink[i].index(max(drink[i]))
#
# print(drink[num-1][drink[num-1][3]])

for i in range(3, num+1):
    drink[i] = max(drink[i-2] + amount[i], drink[i-3] + amount[i-1] + amount[i])
    drink[i] = max(drink[i], drink[i-1])

print(drink[num])
