class Solution {
public:
    
    void recur(int currtotal, int &total, vector<int> & candidates, set<vector<int>>&ans, vector<int>& current) {
        if(currtotal == total) {
            vector<int> temp = current;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(currtotal > total) {
            return;
        }
        
        for(auto x : candidates) {
            current.push_back(x);
            recur(currtotal + x,total,candidates,ans,current);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> current;
        recur(0,target,candidates,ans,current);
        for(auto x : ans) {
            res.push_back(x);
        }
        return res;
        
    }
};