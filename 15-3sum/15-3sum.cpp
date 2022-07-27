class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int> &nums, int start, int end, int target) {
        map<int,int> m;
        vector<vector<int>> ans;
        if(nums[start] + nums[start + 1] > target or nums[end] + nums[end - 1] < target) {
            return ans;
        }
        for(int i = start; i <= end; i++) {
            if(m[target - nums[i]] > 0) {
                ans.push_back({min(target - nums[i],nums[i]),max(target - nums[i],nums[i])});
            }
            m[nums[i]]++;
        }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size() - 1;
        for(int i = 0; i < nums.size() - 2; i++) {
            vector<vector<int>> tmp = twoSum(nums,i + 1,n,-nums[i]);
            for(auto x : tmp) {
                vector<int> t = x;
                t.push_back(nums[i]);
                sort(t.begin(),t.end());
                ans.insert(t);
            }
            while(i + 1 < nums.size() and nums[i] == nums[i+1]) {
                i++;
            }
        }
        vector<vector<int>> res;
        for(auto x : ans) {
            res.push_back(x);
        }
        return res;
    }
};