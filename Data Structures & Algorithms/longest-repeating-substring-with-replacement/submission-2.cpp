class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int mf = 0;
        int wl = 0;
        int ans= 0;
        
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            mf = max(mf, mp[s[r]]);
            while ((r - l + 1) - mf > k) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
