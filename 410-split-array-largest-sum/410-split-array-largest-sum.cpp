class Solution {
public:
    
    int splitsReq(vector<int> &nums, int maxAllowed) {
        int currSum = 0, splits = 0;
        for(int i : nums) {
            if(i + currSum <= maxAllowed) {
                currSum += i;
            }
            else {
                splits++;
                currSum = i;
            }
        }
        return splits;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int maxi = INT_MIN, sum = 0;
        for(auto x : nums) {
            maxi = max(maxi, x);
            sum += x;
        }
        int left = maxi, right = sum, ans = 0;
        while(left <= right) {
            int mid = (left + right)/2;
            if(splitsReq(nums,mid) + 1 <= m) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};