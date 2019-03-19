import math
class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(0, math.floor(len(s)/2)):

            tmp=s[i]
            s[i]=s[-1-i]           
            s[-1-i]=tmp
