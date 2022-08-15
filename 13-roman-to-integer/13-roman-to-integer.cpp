class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'I' and i + 1 < s.length() and s[i+1] == 'V') {
                ans += 4;
                i++;
                continue;
            }
            
            if(s[i] == 'I' and i + 1 < s.length() and s[i+1] == 'X') {
                ans += 9;
                i++;
                continue;
            }
            
            if(s[i] == 'X' and i + 1 < s.length() and s[i+1] == 'L') {
                ans += 40;
                i++;
                continue;
            }
            
            if(s[i] == 'X' and i + 1 < s.length() and s[i+1] == 'C') {
                ans += 90;
                i++;
                continue;
            }
            
            if(s[i] == 'C' and i + 1 < s.length() and s[i+1] == 'D') {
                ans += 400;
                i++;
                continue;
            }
            
            if(s[i] == 'C' and i + 1 < s.length() and s[i+1] == 'M') {
                ans += 900;
                i++;
                continue;
            }
            ans += m[s[i]];
        }
        return ans;
    }
};