n = int(input())
result =[['' for j in range(3)] for j in range(n)]
sum = [0 for t in range(3)]
for  i in range(n):
    result[i][0],result[i][1],result[i][2] = input().split()
def finding(a,sum):               
    compare=[[0 for x in range(2)] for z in range(3)]
    check=0
    for i in range(3):
        for j in range(3):
            if(i==j):
                continue
            else:
                compare[i][check]=int(sum[j])
                check=check+1
        check=0
    for k in range(3):
        sum[k]=int(result[a][k])+int(min(compare[k]))
for q in range(3):
    sum[count]=result[n-1][q]
    count=count+1
v =n-2
for r in range(n-1):
    finding(v,sum)
    v=v-1
print(min(sum))







