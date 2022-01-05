class Solution {
public:
    
    bool checkwithout(string s, int i) {
        s = s.substr(0,i) + s.substr(i+1);
        for(int i = 0; i < s.length()/2; i++) {
            if(s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        for(int i = 0; i < s.length()/2; i++) {
            
            if(s[i] != s[s.length() - 1 - i]) {
                return checkwithout(s,i) or checkwithout(s,s.length()-1-i);
            }
            
        }
        return true;
        
    }
};