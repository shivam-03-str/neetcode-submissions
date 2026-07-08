class Solution {
public:
    int maxProfit(vector<int>& nums) {
        if(nums.empty())return 0;
        int minn=nums[0],ans=0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            ans=max(ans,nums[i]-minn);
            minn=min(minn,nums[i]);
        }
        return ans;
    }
};
