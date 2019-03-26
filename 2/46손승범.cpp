class Solution {
public:
    vector<vector<int>> v;
    void per(vector<int>& nums,int x) {
        if(x==nums.size()){
            v.push_back(nums);
            return;
        }
        for(int i=x;i<nums.size();i++){
            swap(nums[x],nums[i]);
            per(nums,x+1);
            swap(nums[x],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums,0);
        return v;
    }
};
