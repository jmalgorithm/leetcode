a=input()
friend=[]
connect=[]
friend_num=int(a.split()[0])
connect_num=int(a.split()[1])
mat=[[0 for i in range (connect_num)] for j in range(connect_num)]
path=[[0 for i in range (connect_num)] for j in range(connect_num)]
for i in range (connect_num):
    rel=input()
    bet=[]
    for j in range(2):
        bet.append(int(rel.split()[j])-1)
    connect.append(bet)
for i in range(connect_num):
    a = []
    for j in range(1,-1,-1):
        a.append(connect[i][j])
    connect.append(a)
for i in range(1,friend_num+1):
    friend.append(i-1)
                         #기본값 적용
for i in range(connect_num):
    for j in range(connect_num):
        if (i == j):
            mat[i][j]=0
        else:
            aa=[i,j]
            if(aa in connect):
                mat[i][j]=1


def find(start,end,finding,adding):
    print("start: ",start," end: ",end," finding: ",finding," adding: ",adding)
    if(adding >=friend_num):
        return 0
    else:
        if(mat[end][finding]!=0):
            if(adding<mat[start][finding] or mat[start][finding]==0):
                print("find!")
                print(end,"->",finding)
                return adding+mat[end][finding]-1
        else:
            list = []
            for k in range(connect_num):
                if(k==finding):
                    continue
                else:
                    if(mat[end][k]!=0):
                        print(end,"->",k)
                        if(path[end][k] ==0):
                            path[end][k]==1
                            qq=find(end,k,finding,adding+1)
                        else:
                            print("opps! you already been there!")
                        print("qq: ",qq)
                        if(qq==0 or qq==None):
                            continue
                        else:
                            list.append(qq)
            if(len(list)>0):
                print("list: ",list)
                return min(list)

for i in range(connect_num):
    for j in range(connect_num):
        if (i==j):
            continue
        else:
            if(mat[i][j]==0):
                print(i,"->",j)
                aaaa=find(i,j,i,1)
                mat[i][j]=aaaa
                mat[j][i]=aaaa
                for k in range(connect_num):
                    for q in range(connect_num):
                        path[k][q]=0
                print(mat)
            else:
                continue
print(mat)
li=[]
for i in range(len(mat)):
    li.append(sum(mat[i]))
print(li)
mini=999999999
pos=0
for i in range(len(li)):
    if(li[i]<mini):
        pos=i
        mini=li[i]
print(pos+1)