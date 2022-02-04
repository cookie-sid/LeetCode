class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length,0);
        for(auto x : updates) {
            
            ans[x[0]] += x[2];
            if(x[1] + 1 < length) {
                ans[x[1] + 1] -= x[2];
            }
            
        }
        
        int curr = ans[0];
        for(int i = 1; i < ans.size(); i++) {
            curr += ans[i];
            ans[i] = curr;
        }
        
        return ans;
    }
};