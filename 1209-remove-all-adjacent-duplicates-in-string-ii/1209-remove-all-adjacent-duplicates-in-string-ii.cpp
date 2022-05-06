class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(char c : s) {
            if(stk.empty() or stk.top().first != c) {
                stk.push({c, 1});
            } else {
                stk.top().second += 1;
                if(stk.top().second == k) {
                    stk.pop();
                }
            }
        }
        
        string ans = "";
        while(!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            char c = top.first;
            int howMany = top.second;
            for(int i = 0; i < howMany; i++) {
                ans += c;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};