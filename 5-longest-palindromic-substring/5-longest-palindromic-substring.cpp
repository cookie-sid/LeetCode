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
        string ans = "";
        ans += s[0];
        int finall = 0, finalr = 0;
        for(int i = 1; i < s.length(); i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 and s[l] == s[r]) {
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l + 1 > finalr - finall + 1) {
                finalr = r;
                finall = l;
            }
            l = i - 1;
            r = i;
            while(l >= 0 and s[l] == s[r]) {
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l + 1 > finalr - finall + 1) {
                finalr = r;
                finall = l;
            }
        }
        ans = s.substr(finall,finalr - finall + 1);
        return ans;
        
    }
};