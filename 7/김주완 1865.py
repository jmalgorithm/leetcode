def norm(a):  # %값을 소수점으로 변환
    return int(a)/100
def dfs(employee, prob):
    global N, answer  # N: 방의 개수, answer: 끝까지 구한 확률들 중 최대값
    if answer >= prob:  # 연산이 끝난 answer보다 연산이 남은 prob의 확률이 더 작으면 prunning
        return
    if employee == N or prob == 0:  # prob의 연산이 끝까지 왔을 때 answer와 비교
        answer = prob if prob > answer else answer  # (in C) prob : answer ? prob > answer
        return
    else: # 탐색
        for i in range(N):
            if not worked[i]:
                worked[i] = True
                dfs(employee + 1, prob * P[employee][i])
                worked[i] = False

for test_case in range(1, int(input())+1):
    N = int(input())    # 1 <= N <= 16, 0 <= P <= 100
    P = [list(map(norm, input().split())) for _ in range(N)]
    worked = [False] * N  # 각 work(0~N-1)를 맡은 사람이 있는 지를 확인하는 
    answer = 0
    dfs(0, 100) # 직원 number(0~N-1), 최초확률(100%)
    print('#{} {:.6f}'.format(test_case, round(answer, 6)))
