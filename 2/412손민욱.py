class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result=[]
        i=1
        while(i<=n):
            if int(i)%15 == 0:
                result.append("FizzBuzz")
            elif int(i)%3==0:
                result.append("Fizz")
            elif int(i)%5 is 0:
                result.append("Buzz")
            else:
                result.append(str(i))
            i=i+1
        return result