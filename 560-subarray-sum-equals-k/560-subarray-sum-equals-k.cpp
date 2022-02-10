class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count = 0, sum = 0;
        for(auto x : nums) {
            sum += x;
            if(sum == k)
                count++;
            count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};