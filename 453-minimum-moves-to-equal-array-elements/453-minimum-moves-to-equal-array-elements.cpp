class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0, prev = 0, prevnum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            moves += nums[i] + prev - prevnum;
            prevnum = nums[i] + prev;
            prev = moves;
        }
        return moves;
    }
};