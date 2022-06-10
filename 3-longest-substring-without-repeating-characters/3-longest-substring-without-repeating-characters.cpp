class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;
        int start = 1, ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(last[s[i]] != 0) {
                start = max(last[s[i]] + 1,start);
            }
            last[s[i]] = i + 1;
            ans = max(ans,i + 1 - start + 1);
        }
        return ans;
    }
};