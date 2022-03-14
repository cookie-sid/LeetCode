class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0, end = (int)nums.size() - 1;
        vector<int> ans;
        while(start < end) {
            if(nums[start] + nums[end] > target) {
                end--;
            }
            else if(nums[start] + nums[end] < target) {
                start++;
            }
            else {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                break;
            }
        }
        return ans;
    }
};