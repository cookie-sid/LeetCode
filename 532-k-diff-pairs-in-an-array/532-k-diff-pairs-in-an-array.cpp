class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int upper = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + k) - nums.begin();
            if(nums[upper - 1] == nums[i] + k and upper != i + 1) {
                count++;
            }
            while(i < nums.size() - 1 and nums[i + 1] == nums[i])
                i++;
        }
        return count;
    }
};