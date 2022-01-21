class Solution {
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i + 1;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(m[-nums[i]-nums[j]] > j + 1) {
                    ans.push_back({nums[i],nums[j],-nums[i]-nums[j]});
                }
                while(j < nums.size() - 1 and nums[j] == nums[j+1]) {
                    j++;
                }
            }
            while(i < nums.size() - 2 and nums[i] == nums[i+1]) {
                i++;
            }
        }
        return ans;
    }
};