class Solution {
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; i++) {
            
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] < -nums[i]) {
                    l++;
                }
                else if(nums[l] + nums[r] > -nums[i]) {
                    r--;
                }
                else {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l + 1 < r and nums[l + 1] == nums[l]) {
                        l++;
                    }
                    while(r - 1 > l and nums[r - 1] == nums[r]) {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
            
            while(i < nums.size() - 2 and nums[i] == nums[i+1]) {
                i++;
            }
        }
        return ans;
    }
};