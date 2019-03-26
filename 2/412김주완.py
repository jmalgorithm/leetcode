class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ls = []
        for i in range(n):
            if (i + 1)%3 == 0 and (i + 1)%5 == 0:
                ls.append("FizzBuzz")
            elif (i + 1)%3 == 0:
                ls.append("Fizz")
            elif (i + 1)%5 == 0:
                ls.append("Buzz")
            else:
                ls.append(str(i+1))
        return ls
