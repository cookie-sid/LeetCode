class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size());
        int lastoneat = -1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = max(lastoneat + 1,i+1); j < i + nums[i] + 1 and j < nums.size(); j++) {
                steps[j] = steps[i] + 1;
                lastoneat = j;
            }
        }
        return steps[(int)nums.size() - 1];
    }
};