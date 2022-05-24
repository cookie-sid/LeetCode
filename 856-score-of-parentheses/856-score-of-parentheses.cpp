class Solution {
public:
    
    
    
    int scoreOfParentheses(string s) {
        
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' and s[i + 1] == ')') {
                ans += 1;
                i++;
            }
            else {
                int opens = 1, closes = 0, start = i, end = i;
                end++;
                while(end < n and opens != closes) {
                    if(s[end] == '(')
                        opens++;
                    else
                        closes++;
                    
                    end++;
                }
                ans += 2 * scoreOfParentheses(s.substr(start + 1,end - 1 - start - 1));
                i = end - 1;
            }
        }
        return ans;
    }
};