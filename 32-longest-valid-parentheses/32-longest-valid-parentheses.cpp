class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) {
            return 0;
        }
        stack<pair<int,char>> stk;
        int n = s.length();
        vector<int> longestEndingAtThis(n);
        longestEndingAtThis[0] = 0;
        stk.push(make_pair(0,s[0]));
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == '(') {
                stk.push(make_pair(i,'('));
            }
            else {
                if(stk.empty()) {
                    stk.push(make_pair(i,')'));
                }
                auto top = stk.top();
                if(top.second == '(') {
                    if(top.first > 0)
                        longestEndingAtThis[i] = longestEndingAtThis[top.first - 1] + i - top.first + 1;
                    else 
                        longestEndingAtThis[i] = i - top.first + 1;
                    
                    ans = max(ans,longestEndingAtThis[i]);
                    stk.pop();
                }
                else {
                    stk.push(make_pair(i,')'));
                }
            }
        }
        
        return ans;
    }
};