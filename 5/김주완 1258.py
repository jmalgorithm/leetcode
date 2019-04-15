test = int(input())

for C in range(1, test + 1):
    n = int(input())
    board = []
    for i in range(n):
        board += [list(map(int, input().split()))]
    col_matr = []
    row_matr = []
    start = None
    for i in range(n):
        for j in range(n):
            if board[i][j] != 0:
                if start is None:
                    start = [i, j]
                    if j == n-1:
                        col_matr += [start]
                        col_matr += [[i, j]]
                        start = None
                    elif board[i][j+1] == 0:
                        col_matr += [start]
                        col_matr += [[i, j]]
                        start = None
                else:
                    if j == n-1:
                        col_matr += [start]
                        col_matr += [[i, j]]
                        start = None
                    elif board[i][j+1] == 0:
                        col_matr += [start]
                        col_matr += [[i, j]]
                        start = None
    end = None
    for j in range(n):
        for i in range(n):
            if board[i][j] != 0:
                if end is None:
                    end = [i, j]
                    if i == n-1:
                        row_matr += [end]
                        row_matr += [[i, j]]
                        end = None
                    elif board[i+1][j] == 0:
                        row_matr += [end]
                        row_matr += [[i, j]]
                        end = None
                else:
                    if i == n-1:
                        row_matr += [end]
                        row_matr += [[i, j]]
                        end = None
                    elif board[i+1][j] == 0:
                        row_matr += [end]
                        row_matr += [[i, j]]
                        end = None
    col = {}
    for i in range(0, len(col_matr), 2):
        col[tuple(col_matr[i])] = [col_matr[i+1][0] - col_matr[i][0], col_matr[i+1][1] - col_matr[i][1]]
    row = {}
    for i in range(0, len(row_matr), 2):
        row[tuple(row_matr[i])] = [row_matr[i+1][0] - row_matr[i][0], row_matr[i+1][1] - row_matr[i][1]]

    matr = []
    for (i, j) in col.keys():
        if (i, j) in row.keys():
            matr += [[row[(i, j)][0]+1, col[(i, j)][1]+1, (row[(i, j)][0]+1) * (col[(i, j)][1]+1)]]
    matr.sort(key=lambda i: (i[2], i[0]))
    answer = []
    for i in range(len(matr)):
        answer += [str(matr[i][0]), str(matr[i][1])]
    print("#" + str(C), len(matr), ' '.join(answer))
