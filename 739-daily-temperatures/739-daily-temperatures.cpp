class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans(temperatures.size());
        stack<int> s;
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            if(i == temperatures.size() - 1) {
                s.push(i);
                ans[i] = 0;
                continue;
            }
            while(!s.empty() and temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if(s.empty())
                ans[i] = 0;
            else
                ans[i] = s.top() - i;
            s.push(i);
        }
        return ans;
    }
};