class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int n = nums.size();
        if(nums[0] < nums[n - 1]) {
            return nums[0];
        }
        
        int start = 0, end = n-1, ind = -1;
        
        while(start < end) {
            int mid = (start + end)/2;
            
            if(mid > 0 and nums[mid] < nums[mid - 1]) {
                ind = mid;
                break;
            }
            
            if(nums[mid] > nums[end]) {
                start = mid + 1;
                ind = (start + end)/2;
            }
            else {
                end = mid - 1;
                ind = (start + end)/2;
            }
        }
        
        return nums[ind];
        
    }
};