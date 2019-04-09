
import sys

board = []
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]] # north, east, south, west
for i in range(12):
    board.append(list(sys.stdin.readline()))

def color_chain(x, y, color, route, pre_dir):
    if x < 0 or x > 11 or y < 0 or y > 5:
        pass
    elif board[x][y] != color:
        pass
    elif [x, y] not in route:
        route += [[x, y]]
        for dir in directions:
            if dir != pre_dir*(-1):
                color_chain(x + dir[0], y + dir[1], color, route, dir)

def rebuild():
    for i in range(12):
        for j in range(6):
            que = ['.'] * 12
            for i in range(12):
                if board[i][j] != '.':
                    que.remove('.')
                    que.append(board[i][j])
            for i in range(12):
                board[i][j] = que[i]
count = 0

while True:
    chains = []
    for x in range(12):
        for y in range(6):
            if board[x][y] != '.':
                chain = []
                color_chain(x, y, board[x][y], chain, [0, 0])
                if len(chain) > 3:
                    for idx in chain:
                        board[idx[0]][idx[1]] = "."
                    chains += chain
    if len(chains) > 0:
        count += 1
        rebuild()
    else:
        break

print(count)
