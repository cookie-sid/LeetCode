class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        vector<int> lis;
        for(int i = 0; i < envelopes.size(); i++) {
            int index = lower_bound(lis.begin(),lis.end(),envelopes[i][1]) - lis.begin();
            if(index >= lis.size()) {
                lis.push_back(envelopes[i][1]);
            }
            else {
                lis[index] = envelopes[i][1];
            }
        }
        
        
        return lis.size();
    }
};