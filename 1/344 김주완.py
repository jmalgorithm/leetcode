class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        len2 = len(s)
        for i in range(len2//2):
            tmp = s[i]
            s[i] = s[len2 - 1 - i]
            s[len2 - 1 - i] = tmp
