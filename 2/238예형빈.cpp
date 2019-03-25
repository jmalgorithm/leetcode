class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftMul;
        vector<int> rightMul;
        vector<int> answer;
        long long leftMu=1,rightMu=1;
        for(int i=0;i<nums.size();i++){
            leftMu *= nums[i];
            leftMul.push_back(leftMu);
            rightMu *= nums[nums.size()-i-1];
            rightMul.push_back(rightMu);
        }
        for(int i=0;i<nums.size();i++){
            if(i==0)
                answer.push_back(rightMul[nums.size()-2]);
            else if(i==nums.size()-1)
                answer.push_back(leftMul[nums.size()-2]);
            else
                answer.push_back(leftMul[i-1]*rightMul[nums.size()-2-i]);
        }
        return answer;
    }
};