class Solution {
public:
    
    bool check(vector<int> &a , vector<int> &b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) {
            return {};
        }
        vector<int> p_chars(26), curr(26);
        for(auto x : p) {
            p_chars[x - 'a']++;
        }
        for(int i = 0; i < p.length(); i++) {
            curr[s[i] - 'a']++;
        }
        vector<int> ans;
        if(check(p_chars,curr)) {
            ans.push_back(0);
        }
        for(int i = 1; i < s.length() - p.length() + 1; i++) {
            curr[s[i-1] - 'a']--;
            curr[s[i + p.length() - 1] - 'a']++;
            if(check(p_chars,curr)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};