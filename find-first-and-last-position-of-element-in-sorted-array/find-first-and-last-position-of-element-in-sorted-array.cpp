class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        int first = -1, last = -1;
        while(low <= high) {
            int mid = low + high;
            mid /= 2;
            if(mid > 0) {
                if(nums[mid] == target) {
                    if(nums[mid - 1] < target) {
                        first = mid;
                        break;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                if(nums[mid] < target) {
                    low = mid + 1;
                }
                if(nums[mid] > target) {
                    high = mid - 1;
                }
            }
            if(mid == 0) {
                if(nums[mid] == target) {
                    first = mid;
                    break;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        low = 0;
        high = nums.size() - 1;
        while(low <= high) {
            int mid = low + high;
            mid /= 2;
            if(mid < nums.size() - 1) {
                if(nums[mid] == target) {
                    if(nums[mid + 1] > target) {
                        last = mid;
                        break;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                if(nums[mid] < target) {
                    low = mid + 1;
                }
                if(nums[mid] > target) {
                    high = mid - 1;
                }
            }
            if(mid == nums.size() - 1) {
                if(nums[mid] == target) {
                    last = mid;
                    break;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return {first,last}; 
        
    }
};