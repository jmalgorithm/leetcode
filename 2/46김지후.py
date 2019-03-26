class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]
        
        def build(array, remain):
            a=[]
            for i in range(len(remain)):
                a.append(array[:])
            #level -1
            if(len(remain)==1):
                a[0].append(remain[0])
                res.append(a[0])
            #level -2
            elif(len(remain)==2):
                a[0].append(remain[0])
                a[0].append(remain[1])
                a[1].append(remain[1])
                a[1].append(remain[0])
                print(a)
                res.append(a[0])
                res.append(a[1])
            #else...
            else:
                for i in range(len(remain)):
                    #print(remain)
                    b=remain[:i] + remain[i+1 :]
                    a[i].append(remain[i])
                    print(a[i])
                    print(b)
                    build(a[i], b)

        build(res,nums)
        res.sort()
        print(res)
        return res
