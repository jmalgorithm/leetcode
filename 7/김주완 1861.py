from collections import deque

T = int(input())

directions = [[1, 0], [0, 1], [-1, 0], [0, -1]] # north, east, south, west

for test_case in range(1, T+1):
    N = int(input())    # 1 <= N <= 1000
    rooms = [list(map(int, input().split())) for _ in range(N)] # 각 요소는 모두 서로 다른 수

    def bfs(start):
        Q = deque([start])
        visit = 0
        while Q:
            (x, y) = Q.popleft()
            visit += 1
            for dir in directions:
                nx, ny = x + dir[0], y + dir[1]
                if 0 <= nx < N and 0 <= ny < N:
                    if rooms[nx][ny] == rooms[x][y] + 1:
                        Q.append((nx, ny))
        return visit  # 방문 가능한 방의 개수
    maximum = 0
    max_rooms = [rooms[0][0]]
    for i in range(N):
        for j in range(N):
            visit = bfs((i, j)) # 각 (i, j)의 위치에서 시작해 방문가능한 방의 개수를 구한다
            # 방문 가능한 방의 개수 중 최대값
            if maximum <= visit:
                # visit가 최대값이랑 같으면 배열에 추가
                if maximum == visit:
                    max_rooms += [rooms[i][j]]
                # visit가 최초의 최대값이면 새로 배열을 
                else:
                    maximum = visit
                    max_rooms = [rooms[i][j]]
    print('#{} {} {}'.format(test_case, min(max_rooms), maximum))
