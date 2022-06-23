class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(auto x : nums) {
            sum += x;
        }
        int ways = 0;
        long long lsum = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            sum -= nums[i];
            lsum += nums[i];
            if(lsum >= sum)
                ways++;
        }
        return ways;
    }
};