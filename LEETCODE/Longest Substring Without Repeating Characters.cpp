class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int mx = 0;
        unordered_map<char,int>mp;
        while(j < s.size()) {
            mp[s[j]]++;

            if(mp.size() == j-i+1){
                mx = max(mx, j-i+1);
            }

            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};
