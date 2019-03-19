class Solution {
public:
    string itoa(int num){
        string str="";
        string a="";
        while(num!=0){
            a+=num%10+48;
            a+=str;
            str=a;
            a="";
            num/=10;
        }
        return str;
    }
    vector<string> fizzBuzz(int n) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<string> v;
        for(int i=1;i<=n;i++)
            if(i%3==0&&i%5==0){
                v.push_back("FizzBuzz");
            }else if(i%3==0){
                v.push_back("Fizz");
            }else if(i%5==0){
                v.push_back("Buzz");
            }else{
                v.push_back(itoa(i));
            }
        return v;
    }
};