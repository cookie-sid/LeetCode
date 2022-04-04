class Solution {
public:
    bool val(string s) {
        for(int i = 0; i < s.length()/2; i++) {
            if(s[i] != s[(s.length()) - i - 1])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int ind = -1, n = s.length();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n - i - 1]) {
                string s1 = s.substr(0,i) + s.substr(i+1);
                string s2 = s.substr(0,n - i - 1) + s.substr(n - i);
                if(val(s1) or val(s2)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};