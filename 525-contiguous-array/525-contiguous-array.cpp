class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> diff;
        int ans = 0;
        int countones = 0 ,countzeros = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                countones++;
            else
                countzeros++;
            
            if(countzeros == countones)
                ans = max(ans,i + 1);
            
            if(diff[countzeros - countones] == 0) {
                diff[countzeros - countones] = i + 1;
            }
            else {
                ans = max(ans,i - diff[countzeros - countones] + 1);
            }
        }
        return ans;
    }
};