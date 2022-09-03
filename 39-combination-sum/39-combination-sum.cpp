class Solution {
public:
    
    void recur(int currtotal, int &total, vector<int> &candidates, set<vector<int>>&ans, vector<int>& current, int i) {
        if(i == candidates.size()) {
            return;
        }
        if(currtotal > total) {
            return;
        }
        if(currtotal == total) {
            ans.insert(current);
        }
        recur(currtotal,total,candidates,ans,current,i+1);
        current.push_back(candidates[i]);
        recur(currtotal + candidates[i],total,candidates,ans,current,i);
        current.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> current;
        recur(0,target,candidates,ans,current,0);
        for(auto x : ans) {
            res.push_back(x);
        }
        return res;
        
    }
};