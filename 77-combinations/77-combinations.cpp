class Solution {
public:
    
    void recur(vector<vector<int>>& ans, vector<bool>& taken, vector<int>& curr, int picked, int last, int target) {
        if(picked == target) {
            ans.push_back(curr);
        }
        
        int prev = last;
        for(int i = last + 1; i < taken.size(); i++) {
            if(taken[i]) {
                continue;
            }
            taken[i] = true;
            curr.push_back(i+1);
            last = i;
            recur(ans,taken,curr,picked+1,last,target);
            taken[i] = false;
            last = prev;
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> taken(n);
        
        recur(ans,taken,curr,0,-1,k);
        
        return ans;
        
    }
};