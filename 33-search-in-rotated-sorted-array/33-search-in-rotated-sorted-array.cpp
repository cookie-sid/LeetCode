class Solution {
public:
    
    int bsearch(vector<int>& nums, int l, int h, int target) {
        while(l <= h) {
            int m = (l + h)/2;
            if(nums[m] == target) {
                return m;
            }
            else if(nums[m] > target) {
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int start  = 0, end = nums.size() - 1;
        if(nums[start] < nums[end]) {
            return bsearch(nums,start,end,target);
        }
        
        while(start <= end) {
            int mid = (start + end)/2;
            if(nums[mid] < nums[start]) {
                end = mid - 1;
            }
            else if(nums[mid] > nums[start]) {
                start = mid;
            }
            else {
                if(nums[start] < nums[end])
                    start = end;
                break;
            }
        }
        cout<<start<<endl;
        if(target >= nums[0] and target <= nums[start]) {
            return bsearch(nums,0,start,target);
        }
        return bsearch(nums,start + 1,nums.size() - 1,target);
        
    }
};