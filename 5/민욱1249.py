a=int(input())
move_x=[0,0,-1,1]
move_y=[1,-1,0,0]
for i in range(a):
    size=int(input())
    field=[[0 for j in range(size)] for k in range(size)]
    visit = [[0 for j in range(size)] for k in range(size)]
    visit[0][0]=1
    value = [[0 for j in range(size)] for k in range(size)]
    for j in range(size):
        aa = input()
        for k in range(size):
            field[j][k]=int(aa[k])
    def compare(xx,yy):
        for k in range(4):
            xxx = xx + move_x[k]
            yyy = yy + move_y[k]
            if xxx < 0 or yyy < 0 or xxx >= size or yyy >= size:
                continue
            else:
                if visit[xxx][yyy] == 0 or value[xxx][yyy] > value[xx][yy] + field[xxx][yyy]:
                    if(value[xxx][yyy] > value[xx][yy] + field[xxx][yyy]):
                        value[xxx][yyy] = value[xx][yy] + field[xxx][yyy]
                        visit[xxx][yyy] = 1
                        compare(xxx,yyy)
                    else:
                        value[xxx][yyy] = value[xx][yy] + field[xxx][yyy]
                        visit[xxx][yyy] = 1
    for j in range(size):
        xx=0
        yy=j
        while(yy>=0):
            #print("while1")
            #print("xx: ", xx, "yy: ", yy)
            compare(xx,yy)
            xx+=1
            yy-=1
    for j in range(1,size-1):
        xx = j
        yy = size-1
        while (xx <size):
            #print("while2")
            #print("xx: ",xx,"yy: ",yy)
            compare(xx, yy)
            xx += 1
            yy-=1
    print("#%d %d" % (i+1, value[-1][-1]))