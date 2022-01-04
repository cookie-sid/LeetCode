class Solution {
public:
    
    void recur(vector<int>& candidates, vector<int>& poss, set<vector<int>> &ans, int target) {
        if(target == 0) {
            vector<int> temp = poss;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        for(int i = 0; i < candidates.size(); i++) {
            if(target - candidates[i] >= 0) {
                poss.push_back(candidates[i]);
                recur(candidates,poss,ans,target-candidates[i]);
                poss.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> poss;
        set<vector<int>> ans;
        recur(candidates,poss,ans,target);
        vector<vector<int>> res;
        for(auto x : ans)
            res.push_back(x);
        
        return res;
            
    }
};