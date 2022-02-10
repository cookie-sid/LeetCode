class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0] = 1;
        int count = 0, sum = 0;
        for(auto x : nums) {
            sum += x;
            if(k != 0 and m[sum - k] != 0) {
                count += m[sum - k];
            }
            if(k == 0) {
                if(m[sum] != 0) {
                    count += m[sum];
                }
            }
            m[sum]++;
        }
        return count;
    }
};