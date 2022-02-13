class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int>& nums, int start, vector<int> &curr) {
        if(start == nums.size())
            ans.push_back(curr);
        else {
            helper(ans,nums,start+1,curr);
            curr.push_back(nums[start]);
            helper(ans,nums,start+1,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int start = 0;
        helper(ans,nums,start,curr);
        return ans;
    }
};