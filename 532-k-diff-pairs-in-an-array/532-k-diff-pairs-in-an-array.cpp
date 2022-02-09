class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int temp = 1;
        for(int i = 0; i < nums.size(); i++) {
            temp = max(temp,i + 1);
            int curr = nums[i];
            while(temp < nums.size() and nums[temp] < curr + k) {
                temp++;
            }
            if(temp == nums.size())
                break;
            if(nums[temp] == nums[i] + k) {
                count++;
            }
            while(i < nums.size() - 1 and nums[i + 1] == nums[i]) {
                i++;
            }
            while(temp < nums.size() - 1 and nums[temp + 1] == nums[temp]) {
                temp++;
            }
        }
        return count;
    }
};