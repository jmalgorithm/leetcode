# 각 쇠막대기가 포함하는 레이저의 개수 + 1의 개수로 나눠진다 - 시간 초과
# (각 레이저가 지나는 막대갯수) + 막대 갯수
for test_case in range(1, int(input())+1):
    pos = input()
    stack = []        # '(', ')' 이 둘의 index pair를 알아내기 위한 stack
    pieces, lv = 0, 0 # pieces: 조각의 총 개수, lv: 몇개의 막대가 쌓여있나
    for i in range(len(pos)):
        if pos[i] == '(':
            lv += 1
            stack += [i]
        else:
            if i - stack.pop() == 1:
                lv -= 1       # lv을 한단계 줄여서 레이저의 개수는 lv에서 제외시킴
                pieces += lv  # 레이저가 지나는 막대의 개수를 pieces에 포함시킴
            else:
                lv -= 1       # 막대가 끝나는 지점, 해당 막대를 lv에서 제외
                pieces += 1   # 레이저가 잘라내고 남은 부분을 pieces에 포함시킴
    print('#{} {}'.format(test_case, pieces))
