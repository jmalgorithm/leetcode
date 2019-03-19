class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int size=nums.size();
        vector<int> v1(size,1),v2(size,1);
        for(int i=1;i<size;i++){
            v1[i]=v1[i-1]*nums[i-1];
            v2[i]=v2[i-1]*nums[size-i];
        }
        for(int i=0;i<size;i++){
            nums[i]=v1[i]*v2[size-i-1];
        }
        return nums;
    }
};