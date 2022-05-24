class Solution {
public:
    bool checkValidString(string s) {
        int starsFromRight = 0, n = s.length(), opens = 0, closes = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') {
                if(starsFromRight == 0 and closes == 0) {
                    return false;
                }
                if(closes > 0) {
                    closes--;
                    continue;
                }
                if(starsFromRight > 0) {
                    starsFromRight--;
                    continue;
                }
            }
            else {
                if(s[i] == '*')
                    starsFromRight++;
                else 
                    closes++;
            }
        }
        
        starsFromRight = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(starsFromRight == 0 and opens == 0) {
                    return false;
                }
                if(opens > 0) {
                    opens--;
                    continue;
                }
                if(starsFromRight > 0) {
                    starsFromRight--;
                    continue;
                }
            }
            else {
                if(s[i] == '*')
                    starsFromRight++;
                else 
                    opens++;
            }
        }
        
        return true;
    }
};