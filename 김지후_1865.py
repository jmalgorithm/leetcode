T = int(input())
for case in range(T):
    N = int(input())
    probablity = [[int(x)/100 for x in input().split()] for y in range(N)]

    # recursive funcition
    def travel(row, col, sailor, job):
        res = 0
        if row == N-2:
            for i in range(N):
                if i not in job:
                    tmp=sailor*probablity[row+1][i]
                    if tmp > res:
                        res = tmp
        else:
            for j in range(N):
                if j not in job:
                    par = probablity[row+1][j]
                    tmp=travel(row+1,j,sailor*par, list(job.append(j)))
                    if tmp > res:
                        res =tmp
        return res

    final = 0
    for i in range(N):
        tmp = travel(0,i,probablity[0][i], [i])
        if tmp > final:
            final = tmp

    print("#%d %f" %(case+1, final/100))
