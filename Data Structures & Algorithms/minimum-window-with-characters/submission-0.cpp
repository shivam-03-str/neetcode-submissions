class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(char c : t){
            need[c]++;
        }
        int l = 0,minlen = INT_MAX,have = 0,req=need.size(),start=0;

        for(int r = 0;r<s.size();r++){
            char ch = s[r];
            window[ch]++;
            if(need.count(ch) && window[ch] == need[ch]){
                have++;
            }
            while(have == req){
                if(r-l+1 < minlen){
                    minlen=r-l+1;
                    start=l;
                }

                window[s[l]]--;
                if(need.count(s[l])&&window[s[l]]<need[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return minlen==INT_MAX ? "" : s.substr(start,minlen);
    }
};
