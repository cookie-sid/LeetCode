class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int peak = 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != temp.back()) {
                temp.push_back(nums[i]);
            }
        }
        if(temp.size() == 1) {
            return 1;
        }
        int ans = 2;
        for(int i = 1; i < temp.size() - 1; i++) {
            if((temp[i] > temp[i+1] and temp[i] > temp[i-1]) or (temp[i] < temp[i+1] and temp[i] < temp[i-1])) {
                ans++;
            }
        }
        return ans;
    }
};