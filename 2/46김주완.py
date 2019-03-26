class Solution:
    def makePer(self, que, res, ans):
        if que == []:
            ans.append(res[:])
        else:
            for i in range(len(que)):
                res.append(que[i])
                t = que.pop(i)
                self.makePer(que, res, ans)
                que.insert(i, t)
                res.remove(que[i])
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        answer = []
        self.makePer(nums, result, answer)
        return answer
            
