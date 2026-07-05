class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int  n =  nums.size();
        unordered_map<int,int>pm;
        for(int i = 0;i<n;i++){
            int diff=target-nums[i];
            if(pm.find(diff)!=pm.end()){
                return{pm[diff],i};
            }
            pm.insert({nums[i],i});
        }
        return {};
    }
};
