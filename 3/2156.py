stair = int(input())
result=[[0 for i in range(2)] for j in range(10001)]
count=0
br=[0 for i in range(2)]
nr=[0 for i in range(2)]
for i in range(1,stair+1):
    value=int(input())               #0�� 1ĭ 1�� 2ĭ
    if(i==1):
        result[1][0]=value
    elif(i==2):
        result[2][0]=result[i-1][0]+value
        result[i][1]=value
    else:
        result[i][0]=result[i-1][1]+value
        result[i][1] = max(max(result[i-3]),max(result[i - 2])) + value;
print(max(max(result[stair-1]),max(result[stair])))