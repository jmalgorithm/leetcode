class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        a=[]
        x=1
        n = len(nums)

        for i in range(0,n):
            a.append(x)
            x*=nums[i]
        print(a)
        x=1

        for i in range(n-1,-1,-1):
            a[i]=x*a[i]
            x*=nums[i]

        return a
    
