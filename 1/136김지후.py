class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        print(len(nums))
        for i in range(len(nums)):
            tmp=nums.pop()
            print(tmp)
            try:
                nums.remove(tmp)
            except ValueError:
                return tmp
                
