class Solution {
public:
    void reverseString(vector<char>& s) {
        int length=s.size();
        char temp;
        for(int i=0;i<length/2;i++){
            temp = s[i];
            s[i] = s[length-i-1];
            s[length-i-1]=temp;
        }
    }
};