class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        for(int i=1;i<nums.size();i++){
            nums[0]^=nums[i];
        }
        return nums[0];
    }
};