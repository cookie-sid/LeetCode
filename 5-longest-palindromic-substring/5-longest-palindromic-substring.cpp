class Solution {
public:
    
    bool checkPalin(string s, int n) {
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        unordered_map<char,vector<int>> m;
        int n = s.length();
        string ans = "";
        ans += s[0];
        for(int i = 0; i < n; i++) {
            if(m[s[i]].size() == 0) {
                m[s[i]].push_back(i);
            }
            else {
                for(int j = 0; j < m[s[i]].size(); j++) {
                    if(checkPalin(s.substr(m[s[i]][j], i - m[s[i]][j] + 1),i - m[s[i]][j] + 1)) {
                        if(ans.length() < i - m[s[i]][j] + 1) {
                            ans = s.substr(m[s[i]][j],i - m[s[i]][j] + 1);
                            break;
                        }
                    }
                }
                m[s[i]].push_back(i);
            }
        }
        return ans;
    }
};