class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        do{
             answer.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return answer;
    }
};



class Solution {
public:
    void per(vector<int>& nums,int begin,vector<vector<int>>& result){
        if(begin>=nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            per(nums,begin+1,result);
            swap(nums[begin],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        per(nums,0,result);
        return result;
    }
};
