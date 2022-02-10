class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum % k == 0 and i > 0) {
                return true;
            }
            if(m[sum % k] != 0 and i - m[sum%k] + 1 > 1) 
                return true;
            if(m[sum % k] == 0) {
                m[sum % k] = i + 1;
            }
        }
        return false;
    }
};