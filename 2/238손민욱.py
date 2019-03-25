class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        data= ['' for j in range(len(nums))]
        big =1
        small=1
        for i in range(0,len(nums)):
            data[i]=1
            data[i] = data[i]*big
            big=big*nums[i]
        for j in range(len(nums)-1,-1,-1):
            data[j]=data[j]*small
            small=small*nums[j];
        return data
    