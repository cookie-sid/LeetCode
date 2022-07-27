class Solution {
public:
    
    set<vector<int>> twoSum(vector<int> &nums, int start, int end, int target) {
        map<int,int> m;
        set<vector<int>> ans;
        while(start < end) {
            if(nums[start] + nums[end] > target) {
                while(end - 1 > start and nums[end] == nums[end - 1]) {
                    end--;
                }
                end--;
            }
            else if(nums[start] + nums[end] < target) {
                while(start + 1 < end and nums[start] == nums[start + 1]) {
                    start++;
                }
                start++;
            }
            else {
                ans.insert({nums[start],nums[end]});
                while(start + 1 < end and nums[start] == nums[start + 1]) {
                    start++;
                }
                start++;
                while(end - 1 > start and nums[end] == nums[end - 1]) {
                    end--;
                }
                end--;
            }
        }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size() - 1;
        for(int i = 0; i < nums.size() - 2; i++) {
            set<vector<int>> tmp = twoSum(nums,i + 1,n,-nums[i]);
            for(auto x : tmp) {
                vector<int> t = x;
                t.push_back(nums[i]);
                sort(t.begin(),t.end());
                ans.push_back(t);
            }
            while(i + 1 < nums.size() and nums[i] == nums[i+1]) {
                i++;
            }
        }
        return ans;
    }
};