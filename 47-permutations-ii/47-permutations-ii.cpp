class Solution {
public:
    
    void recur(vector<int> &nums, vector<bool> &taken, set<vector<int>> &s, vector<int> &curr) {
        if(curr.size() == nums.size()) {
            s.insert(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!taken[i]) {
                taken[i] = true;
                curr.push_back(nums[i]);
                recur(nums,taken,s,curr);
                curr.pop_back();
                taken[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<bool> taken(nums.size());
        vector<int> curr;
        recur(nums,taken,s,curr);
        vector<vector<int>> ans;
        for(auto x : s) {
            ans.push_back(x);
        }
        return ans;
        
    }
};