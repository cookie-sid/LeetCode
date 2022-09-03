class Solution {
public:
    
    void funct(vector<int>& nums, int i, int n, vector<int> &curr, set<vector<int>> &ans) {
        if(i == n) {
            ans.insert(curr);
            return;
        }
        funct(nums,i+1,n,curr,ans);
        curr.push_back(nums[i]);
        funct(nums,i+1,n,curr,ans);
        curr.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        funct(nums,0,n,curr,ans);
        vector<vector<int>> res;
        for(auto x : ans) {
            res.push_back(x);
        }
        return res;
    }
};