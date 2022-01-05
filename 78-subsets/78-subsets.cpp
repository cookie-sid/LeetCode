class Solution {
public:
    
    
    void subs(vector<vector<int>> &ans, int k, int n, vector<int> &nums, vector<int> &curr) {
        if(k == n) {
            ans.push_back(curr);
            return;
        }
        subs(ans,k+1,n,nums,curr);
        curr.push_back(nums[k]);
        subs(ans,k+1,n,nums,curr);
        curr.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        subs(ans,0,nums.size(),nums,curr);
        
        return ans;
        
    }
};