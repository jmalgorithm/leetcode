stair = int(input())
result=[[0 for i in range(2)] for j in range(301)]
count=0
for i in range(1,stair+1):
    value=int(input())               #0Àº 1Ä­ 1Àº 2Ä­
    if(i==1):
        result[1][0]=value
    elif(i==2):
        result[2][0]=result[1][0]+value
        result[2][1]=value
    else:
        result[i][0]=result[i-1][1]+value
        result[i][1] = max(result[i-2][0],result[i-2][1])+value
print(max(result[stair][0],result[stair][1]))





