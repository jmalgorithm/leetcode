class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=1;i<=n;i++){
            string temp="";
            if(i%3==0){
                temp="Fizz";
                if(i%5==0)
                temp+="Buzz";
            }
            else if(i%5==0)
                temp+="Buzz";
            else
                temp = to_string(i);
            answer.push_back(temp);
        }
        return answer;
    }
};