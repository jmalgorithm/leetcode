class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        output = [1 for i in range(length)]
        tmp1 = 1
        tmp2 = 1
        for i in range(length):
            output[i] *= tmp1
            tmp1 *= nums[i]
            
            output[-1-i] *= tmp2
            tmp2 *= nums[-1-i]
        return output
