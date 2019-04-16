a=int(input())
for i in range(a):
    size=int(input())
    field=[[0 for j in range(size)]for k in range(size)]
    for j in range(size):
        arr=input()
        for k in range(size):
            field[j][k]=int(arr.split(" ")[k])
    list=[]
    add = 0
    for j in range(size):
        count=0
        for k in range(size):
            if(field[j][k] != 0):
                count+=1
            else:
                if(count!=0):
                    list.insert(add,count)
                    count=0
                    add+=1
        if(count!=0):
            list.insert(add, count)
            add+=1
    result=[]
    for j in range(len(list)):
        cnt=[list[j],list.count(list[j])]
        if (cnt not in result):
            result.append(cnt)
        else:
            continue
    #print("result: ",result)
    answer=[]
    for j in range(len(result)):
        q=[result[j][0]*result[j][1],j]
        answer.append(q)
    answer.sort()
    dup=0
    start=0

    def resort(start,dup):
        #print("start: ",start,dup)
        candi=[]
        for j in range(start,start+dup+1):
            rr=[result[answer[j][1]][1],answer[j][1]]
            candi.append(rr)
        candi.sort()
        #print("candI: ",candi)
        #print("sd: ",start+dup+1)
        for j in range(start,start+dup+1,1):
            #print(j)
            #print("¹Ù²Ü°ª: ",candi[j-start][1])
            answer[j][1]=candi[j-start][1]

    for j in range(len(answer)-1):
        if(answer[j][0]==answer[j+1][0] and dup==0):
            dup+=1
            start=j
        elif(answer[j][0]==answer[j+1][0] and dup!=0):
            dup += 1
        elif(answer[j][0]!=answer[j+1][0] and dup!=0):
            #print("answer: ",answer)
            resort(start,dup)
            start=0
            dup=0
        elif (answer[j][0] != answer[j + 1][0] and dup == 0):
            continue

    #print("answer: ",answer)
    prt=str(len(answer))
    for j in range(len(answer)):
        prt=prt+" "+str(result[answer[j][1]][1])+" "+str(result[answer[j][1]][0])
    print("#%d "%(i+1)+prt)

