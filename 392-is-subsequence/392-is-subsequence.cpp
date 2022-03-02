class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length())
            return false;
        
        int start = 0;
        for(int i = 0; i < t.length() and start < s.length(); i++) {
            if(s[start] == t[i]) {
                start++;
            }
        }
        if(start == s.length())
            return true;
        return false;
    }
};